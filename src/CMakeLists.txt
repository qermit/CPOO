# the next line sets up include and link directories and defines some variables that we will use.
# you can modify the behavior by setting some variables, e.g.
#   set(QT_USE_OPENGL TRUE)
# -> this will cause cmake to include and link against the OpenGL module
if (USE_QT)

include(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
endif (USE_QT)
# see http://cmake.org/cmake/help/cmake2.6docs.html#module:FindQt4 for a complete list

# the variable "qtproject_SRCS" contains all .cpp files of this project

SET(bmodel_SOURCES
		BackgroundModel.cpp  bmodel.cpp  HistogramModel.cpp  MedianModel.cpp  PreviewModel.cpp
		CodebookModel.cpp
)
SET(bmodel_HEADERSQT )

SET(bmodel_HEADERS 
		${bmodel_HEADERSQT}
		BackgroundModel.h
		HistogramModel.h
		MedianModel.h
		PreviewModel.h
		CodebookModel.h
)


if (USE_QT)
QT4_WRAP_CPP(bmodel_HEADERS_MOC ${bmodel_HEADERSQT})
# create an executable file named "qtproject" from the source files in the variable "qtproject_SRCS".
add_executable(bmodel
		${bmodel_SOURCES}
		${bmodel_HEADERS_MOC}
		)

# link the "qtproject" target against the Qt libraries. which libraries exactly, is defined by the "include(${QT_USE_FILE})" line above, which sets up this variable.

target_link_libraries(bmodel ${QT_LIBRARIES} ${OpenCV_LIBS})
else (USE_QT)
add_executable(bmodel
                ${bmodel_SOURCES}
                )
# link the "qtproject" target against the Qt libraries. which libraries exactly, is defined by the "include(${QT_USE_FILE})" line above, which sets up this variable.
target_link_libraries(bmodel ${OpenCV_LIBS})
endif (USE_QT)
