import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

datasets = ["SWEC_ETHZ", "CHBMIT"]
data_files = ["Transfer_SWEC_ETHZ_CHBMIT.csv", "Transfer_CHBMIT_SWEC_ETHZ.csv"]
data = []
for data_file in data_files:
    data_ = pd.read_csv(data_file)
    data_ = data_[
        (data_["Epoch"] == -1) | (data_["Epoch"] == 0) | (data_["Epoch"] == 9)
    ]
    data_ = (
        data_.groupby(["Pretrained Patient", "Evaluation Patient", "Epoch"])
        .agg({"Test Accuracy": ["mean", np.std]})
        .reset_index()
    )
    data_.columns = [
        "Pretrained Patient",
        "Evaluation Patient",
        "Epoch",
        "Test Accuracy_mean",
        "Test Accuracy_std",
    ]
    data_["Epoch"] = data_["Epoch"] + 1
    data.append(data_)

fig, axs = plt.subplots(2, 5)

pretrained_data_files = ["CHBMIT.csv", "SWEC_ETHZ.csv"]
for dataset_idx, pretrained_data_file in enumerate(pretrained_data_files):
    pretrained_data_file = pd.read_csv(pretrained_data_file)
    for patient in pretrained_data_file["Patient"].unique():
        test_set_accuracy = []
        for fold in pretrained_data_file[pretrained_data_file["Patient"] == patient][
            "Fold"
        ].unique():
            test_set_accuracy.append(
                max(
                    pretrained_data_file[
                        (pretrained_data_file["Patient"] == patient)
                        & (pretrained_data_file["Fold"] == fold)
                    ]["Test Accuracy"].values
                )
            )

        test_set_accuracy_mean = np.mean(test_set_accuracy)
        test_set_accuracy_std = np.std(test_set_accuracy)
        pretrained_patient = data[dataset_idx][
            data[dataset_idx]["Evaluation Patient"] == patient
        ]["Pretrained Patient"].values[0]
        # Epoch 100 is arbitrarily chosen as a placeholder
        data[dataset_idx] = data[dataset_idx].append(
            {
                "Pretrained Patient": pretrained_patient,
                "Evaluation Patient": patient,
                "Epoch": 100,
                "Test Accuracy_mean": test_set_accuracy_mean,
                "Test Accuracy_std": test_set_accuracy_std,
            },
            ignore_index=True,
        )

for i in range(len(data_files)):
    for j in range(5):
        pretrained_patient = data[i]["Pretrained Patient"].unique()[j]
        evaluation_patient = data[i]["Evaluation Patient"].unique()[j]
        df = data[i][data[i]["Pretrained Patient"] == pretrained_patient]
        sns.barplot(
            x="Epoch",
            y="Test Accuracy_mean",
            yerr=df["Test Accuracy_std"].values,
            data=df,
            ax=axs[i][j],
        )
        axs[i][j].set_title(
            "Pretrained Patient ({}): ".format(datasets[i]) 
            + str(int(pretrained_patient))
            + "\nEvaluation Patient ({}): ".format(datasets[1 - i])
            + str(int(evaluation_patient))
        )
        axs[i][j].set_xlabel("Epoch")
        axs[i][j].set_ylabel("Test Accuracy (%)")
        axs[i][j].set_ylim(0, 100)
        axs[i][j].set_xticklabels(
            ["0\n(No Retraining Performed)", "1", "10", "Reported\n({} Accuracy)".format(datasets[1 - i])]
        )

plt.show()
