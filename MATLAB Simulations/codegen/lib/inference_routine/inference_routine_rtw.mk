###########################################################################
## Makefile generated for component 'inference_routine'. 
## 
## Makefile     : inference_routine_rtw.mk
## Generated on : Wed Jul 14 15:05:15 2021
## Final product: .\inference_routine.lib
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# COMPILER_COMMAND_FILE   Compiler command listing model reference header paths
# CMD_FILE                Command file
# MODELLIB                Static library target

PRODUCT_NAME              = inference_routine
MAKEFILE                  = inference_routine_rtw.mk
MATLAB_ROOT               = C:\PROGRA~1\MATLAB\R2021a
MATLAB_BIN                = C:\PROGRA~1\MATLAB\R2021a\bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)\win64
START_DIR                 = E:\MEMRIS~1\MATLAB~1\codegen\lib\INFERE~1
TGT_FCN_LIB               = ISO_C++11
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
COMPILER_COMMAND_FILE     = inference_routine_rtw_comp.rsp
CMD_FILE                  = inference_routine_rtw.rsp
C_STANDARD_OPTS           = 
CPP_STANDARD_OPTS         = 
NODEBUG                   = 1
MODELLIB                  = inference_routine.lib

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Microsoft Visual C++ 2019 v16.0 | nmake (64-bit Windows)
# Supported Version(s):    16.0
# ToolchainInfo Version:   2021a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# NODEBUG
# cvarsdll
# cvarsmt
# conlibsmt
# ldebug
# conflags
# cflags

#-----------
# MACROS
#-----------

MW_EXTERNLIB_DIR    = $(MATLAB_ROOT)\extern\lib\win64\microsoft
MW_LIB_DIR          = $(MATLAB_ROOT)\lib\win64
CPU                 = AMD64
APPVER              = 5.02
CVARSFLAG           = $(cvarsmt)
CFLAGS_ADDITIONAL   = -D_CRT_SECURE_NO_WARNINGS
CPPFLAGS_ADDITIONAL = -EHs -D_CRT_SECURE_NO_WARNINGS /wd4251
LIBS_TOOLCHAIN      = $(conlibs)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Microsoft Visual C Compiler
CC = cl

# Linker: Microsoft Visual C Linker
LD = link

# C++ Compiler: Microsoft Visual C++ Compiler
CPP = cl

# C++ Linker: Microsoft Visual C++ Linker
CPP_LD = link

# Archiver: Microsoft Visual C/C++ Archiver
AR = lib

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)\mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: NMAKE Utility
MAKE = nmake


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -Zi
C_OUTPUT_FLAG       = -Fo
LDDEBUG             = /DEBUG
OUTPUT_FLAG         = -out:
CPPDEBUG            = -Zi
CPP_OUTPUT_FLAG     = -Fo
CPPLDDEBUG          = /DEBUG
OUTPUT_FLAG         = -out:
ARDEBUG             =
STATICLIB_OUTPUT_FLAG = -out:
MEX_DEBUG           = -g
RM                  = @del
ECHO                = @echo
MV                  = @ren
RUN                 = @cmd /C

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = /nologo
CFLAGS               = $(cflags) $(CVARSFLAG) $(CFLAGS_ADDITIONAL) \
                       /O2 /Oy-
CPPFLAGS             = /TP $(cflags) $(CVARSFLAG) $(CPPFLAGS_ADDITIONAL) \
                       /O2 /Oy-
CPP_LDFLAGS          = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
CPP_SHAREDLIB_LDFLAGS  = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                         -dll -def:$(DEF_FILE)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = $(ldebug) $(conflags) $(LIBS_TOOLCHAIN) \
                       -dll -def:$(DEF_FILE)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = .\inference_routine.lib
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = 

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=inference_routine

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)\CXSparse\Source\cs_ri_bundle.cpp $(START_DIR)\CXSparse\Source\cs_ci_bundle.cpp $(START_DIR)\CXSparse\CXSparseSupport\solve_from_lu.cpp $(START_DIR)\CXSparse\CXSparseSupport\solve_from_qr.cpp $(START_DIR)\CXSparse\CXSparseSupport\makeCXSparseMatrix.cpp $(START_DIR)\CXSparse\CXSparseSupport\unpackCXStruct.cpp $(START_DIR)\inference_routine_data.cpp $(START_DIR)\inference_routine_initialize.cpp $(START_DIR)\inference_routine_terminate.cpp $(START_DIR)\inference_routine.cpp $(START_DIR)\rand.cpp $(START_DIR)\voltage_deg_model_sparse_conductance.cpp $(START_DIR)\sparse.cpp $(START_DIR)\minOrMax.cpp $(START_DIR)\eml_rand_mt19937ar_stateful.cpp $(START_DIR)\insertionsort.cpp $(START_DIR)\introsort.cpp $(START_DIR)\heapsort.cpp $(START_DIR)\sparse1.cpp $(START_DIR)\stack1.cpp

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = cs_ri_bundle.obj cs_ci_bundle.obj solve_from_lu.obj solve_from_qr.obj makeCXSparseMatrix.obj unpackCXStruct.obj inference_routine_data.obj inference_routine_initialize.obj inference_routine_terminate.obj inference_routine.obj rand.obj voltage_deg_model_sparse_conductance.obj sparse.obj minOrMax.obj eml_rand_mt19937ar_stateful.obj insertionsort.obj introsort.obj heapsort.obj sparse1.obj stack1.obj

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS = 

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_ = /source-charset:utf-8
CFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CFLAGS = $(CFLAGS) $(CFLAGS_) $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_ = /source-charset:utf-8
CPPFLAGS_BASIC = $(DEFINES) @$(COMPILER_COMMAND_FILE)

CPPFLAGS = $(CPPFLAGS) $(CPPFLAGS_) $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################


!include $(MATLAB_ROOT)\rtw\c\tools\vcdefs.mak


###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute set_environment_variables


all : build
	@cmd /C "@echo ### Successfully generated all binary outputs."


build : set_environment_variables prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


set_environment_variables : 
	@set INCLUDE=$(INCLUDES);$(INCLUDE)
	@set LIB=$(LIB)


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@cmd /C "@echo ### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS) -out:$(PRODUCT) @$(CMD_FILE)
	@cmd /C "@echo ### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(RELATIVE_PATH_TO_ANCHOR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{E:\MEMRIS~1\MATLAB~1}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{E:\MEMRIS~1\MATLAB~1}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\CXSparse\Source}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\CXSparse\Source}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


{$(START_DIR)\CXSparse\CXSparseSupport}.c.obj :
	$(CC) $(CFLAGS) -Fo"$@" "$<"


{$(START_DIR)\CXSparse\CXSparseSupport}.cpp.obj :
	$(CPP) $(CPPFLAGS) -Fo"$@" "$<"


cs_ri_bundle.obj : $(START_DIR)\CXSparse\Source\cs_ri_bundle.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_ri_bundle.cpp


cs_ci_bundle.obj : $(START_DIR)\CXSparse\Source\cs_ci_bundle.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\CXSparse\Source\cs_ci_bundle.cpp


solve_from_lu.obj : $(START_DIR)\CXSparse\CXSparseSupport\solve_from_lu.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\CXSparse\CXSparseSupport\solve_from_lu.cpp


solve_from_qr.obj : $(START_DIR)\CXSparse\CXSparseSupport\solve_from_qr.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\CXSparse\CXSparseSupport\solve_from_qr.cpp


makeCXSparseMatrix.obj : $(START_DIR)\CXSparse\CXSparseSupport\makeCXSparseMatrix.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\CXSparse\CXSparseSupport\makeCXSparseMatrix.cpp


unpackCXStruct.obj : $(START_DIR)\CXSparse\CXSparseSupport\unpackCXStruct.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\CXSparse\CXSparseSupport\unpackCXStruct.cpp


inference_routine_data.obj : $(START_DIR)\inference_routine_data.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\inference_routine_data.cpp


inference_routine_initialize.obj : $(START_DIR)\inference_routine_initialize.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\inference_routine_initialize.cpp


inference_routine_terminate.obj : $(START_DIR)\inference_routine_terminate.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\inference_routine_terminate.cpp


inference_routine.obj : $(START_DIR)\inference_routine.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\inference_routine.cpp


rand.obj : $(START_DIR)\rand.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\rand.cpp


voltage_deg_model_sparse_conductance.obj : $(START_DIR)\voltage_deg_model_sparse_conductance.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\voltage_deg_model_sparse_conductance.cpp


sparse.obj : $(START_DIR)\sparse.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\sparse.cpp


minOrMax.obj : $(START_DIR)\minOrMax.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\minOrMax.cpp


eml_rand_mt19937ar_stateful.obj : $(START_DIR)\eml_rand_mt19937ar_stateful.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\eml_rand_mt19937ar_stateful.cpp


insertionsort.obj : $(START_DIR)\insertionsort.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\insertionsort.cpp


introsort.obj : $(START_DIR)\introsort.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\introsort.cpp


heapsort.obj : $(START_DIR)\heapsort.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\heapsort.cpp


sparse1.obj : $(START_DIR)\sparse1.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\sparse1.cpp


stack1.obj : $(START_DIR)\stack1.cpp
	$(CPP) $(CPPFLAGS) -Fo"$@" $(START_DIR)\stack1.cpp


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(COMPILER_COMMAND_FILE) $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@cmd /C "@echo ### PRODUCT = $(PRODUCT)"
	@cmd /C "@echo ### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@cmd /C "@echo ### BUILD_TYPE = $(BUILD_TYPE)"
	@cmd /C "@echo ### INCLUDES = $(INCLUDES)"
	@cmd /C "@echo ### DEFINES = $(DEFINES)"
	@cmd /C "@echo ### ALL_SRCS = $(ALL_SRCS)"
	@cmd /C "@echo ### ALL_OBJS = $(ALL_OBJS)"
	@cmd /C "@echo ### LIBS = $(LIBS)"
	@cmd /C "@echo ### MODELREF_LIBS = $(MODELREF_LIBS)"
	@cmd /C "@echo ### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@cmd /C "@echo ### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@cmd /C "@echo ### CFLAGS = $(CFLAGS)"
	@cmd /C "@echo ### LDFLAGS = $(LDFLAGS)"
	@cmd /C "@echo ### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### CPPFLAGS = $(CPPFLAGS)"
	@cmd /C "@echo ### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@cmd /C "@echo ### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@cmd /C "@echo ### ARFLAGS = $(ARFLAGS)"
	@cmd /C "@echo ### MEX_CFLAGS = $(MEX_CFLAGS)"
	@cmd /C "@echo ### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@cmd /C "@echo ### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@cmd /C "@echo ### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@cmd /C "@echo ### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@cmd /C "@echo ### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@cmd /C "@echo ### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	@if exist $(PRODUCT) $(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


