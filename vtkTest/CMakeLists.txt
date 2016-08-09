cmake_minimum_required(VERSION 3.0)

set(target vtkTest)

set(CMAKE_PREFIX_PATH

)

set(VTK_DIR "E:/thirdLib/VTK-7.0.0.rc1")
set(VTK_LIBRARY_DIR "E:/thirdLib/VTK-7.0.0.rc1/build/lib/Debug")

project(${target})

#find_package(VTK REQUIRED)

file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.cpp")

set(VTK_LIBS
	QVTKWidgetPlugin.lib
vtkalglib-7.0.lib
vtkChartsCore-7.0.lib
vtkCommonColor-7.0.lib
vtkCommonComputationalGeometry-7.0.lib
vtkCommonCore-7.0.lib
vtkCommonDataModel-7.0.lib
vtkCommonExecutionModel-7.0.lib
vtkCommonMath-7.0.lib
vtkCommonMisc-7.0.lib
vtkCommonSystem-7.0.lib
vtkCommonTransforms-7.0.lib
vtkDICOMParser-7.0.lib
vtkDomainsChemistry-7.0.lib
vtkDomainsChemistryOpenGL2-7.0.lib
vtkexoIIc-7.0.lib
vtkexpat-7.0.lib
vtkFiltersAMR-7.0.lib
vtkFiltersCore-7.0.lib
vtkFiltersExtraction-7.0.lib
vtkFiltersFlowPaths-7.0.lib
vtkFiltersGeneral-7.0.lib
vtkFiltersGeneric-7.0.lib
vtkFiltersGeometry-7.0.lib
vtkFiltersHybrid-7.0.lib
vtkFiltersHyperTree-7.0.lib
vtkFiltersImaging-7.0.lib
vtkFiltersModeling-7.0.lib
vtkFiltersParallel-7.0.lib
vtkFiltersParallelImaging-7.0.lib
vtkFiltersProgrammable-7.0.lib
vtkFiltersSelection-7.0.lib
vtkFiltersSMP-7.0.lib
vtkFiltersSources-7.0.lib
vtkFiltersStatistics-7.0.lib
vtkFiltersTexture-7.0.lib
vtkFiltersVerdict-7.0.lib
vtkfreetype-7.0.lib
vtkGeovisCore-7.0.lib
vtkglew-7.0.lib
vtkGUISupportQt-7.0.lib
vtkGUISupportQtSQL-7.0.lib
vtkhdf5-7.0.lib
vtkhdf5_hl-7.0.lib
vtkImagingColor-7.0.lib
vtkImagingCore-7.0.lib
vtkImagingFourier-7.0.lib
vtkImagingGeneral-7.0.lib
vtkImagingHybrid-7.0.lib
vtkImagingMath-7.0.lib
vtkImagingMorphological-7.0.lib
vtkImagingSources-7.0.lib
vtkImagingStatistics-7.0.lib
vtkImagingStencil-7.0.lib
vtkInfovisCore-7.0.lib
vtkInfovisLayout-7.0.lib
vtkInteractionImage-7.0.lib
vtkInteractionStyle-7.0.lib
vtkInteractionWidgets-7.0.lib
vtkIOAMR-7.0.lib
vtkIOCore-7.0.lib
vtkIOEnSight-7.0.lib
vtkIOExodus-7.0.lib
vtkIOExport-7.0.lib
vtkIOGeometry-7.0.lib
vtkIOImage-7.0.lib
vtkIOImport-7.0.lib
vtkIOInfovis-7.0.lib
vtkIOLegacy-7.0.lib
vtkIOLSDyna-7.0.lib
vtkIOMINC-7.0.lib
vtkIOMovie-7.0.lib
vtkIONetCDF-7.0.lib
vtkIOParallel-7.0.lib
vtkIOParallelXML-7.0.lib
vtkIOPLY-7.0.lib
vtkIOSQL-7.0.lib
vtkIOVideo-7.0.lib
vtkIOXML-7.0.lib
vtkIOXMLParser-7.0.lib
vtkjpeg-7.0.lib
vtkjsoncpp-7.0.lib
vtklibxml2-7.0.lib
vtkLocalExample-7.0.lib
vtkmetaio-7.0.lib
vtkmyCommon.lib
vtkmyImaging.lib
vtkmyUnsorted.lib
vtkNetCDF-7.0.lib
vtkNetCDF_cxx-7.0.lib
vtkoggtheora-7.0.lib
vtkParallelCore-7.0.lib
vtkpng-7.0.lib
vtkproj4-7.0.lib
vtkRenderingAnnotation-7.0.lib
vtkRenderingContext2D-7.0.lib
vtkRenderingContextOpenGL2-7.0.lib
vtkRenderingCore-7.0.lib
vtkRenderingFreeType-7.0.lib
vtkRenderingImage-7.0.lib
vtkRenderingLabel-7.0.lib
vtkRenderingLOD-7.0.lib
vtkRenderingOpenGL2-7.0.lib
vtkRenderingQt-7.0.lib
vtkRenderingVolume-7.0.lib
vtkRenderingVolumeOpenGL2-7.0.lib
vtksqlite-7.0.lib
vtksys-7.0.lib
vtktiff-7.0.lib
vtkverdict-7.0.lib
vtkViewsContext2D-7.0.lib
vtkViewsCore-7.0.lib
vtkViewsInfovis-7.0.lib
vtkViewsQt-7.0.lib
vtkzlib-7.0.lib
)

include_directories(${target}
	${VTK_DIR}
	${VTK_DIR}/Common/Core
	${VTK_DIR}/Common/DataModel
	${VTK_DIR}/Common/Color
	${VTK_DIR}/Common/Math
	${VTK_DIR}/Common/Transforms
	${VTK_DIR}/Common/ComputationalGeometry
	${VTK_DIR}/Common/ExecutionModel
	${VTK_DIR}/Filters/Sources
	${VTK_DIR}/Filters/General
	${VTK_DIR}/Filters/Core
	${VTK_DIR}/Rendering/Core
	${VTK_DIR}/Rendering/FreeType
	${VTK_DIR}/build/Common/Core
	${VTK_DIR}/build/Common/DataModel
	${VTK_DIR}/build/Common/Color
	${VTK_DIR}/build/Common/Math
	${VTK_DIR}/build/Common/Transforms
	${VTK_DIR}/build/Common/ComputationalGeometry
	${VTK_DIR}/build/Common/ExecutionModel
	${VTK_DIR}/build/Filters/Sources
	${VTK_DIR}/build/Filters/General
	${VTK_DIR}/build/Filters/Core
	${VTK_DIR}/build/Rendering/Core	
	${VTK_DIR}/build/Rendering/FreeType
)
	
link_directories(${target}
	${VTK_LIBRARY_DIR}
)	

add_executable(${target}
	${HEADERS}
	${SOURCES}
)

target_link_libraries(${target}
	${VTK_LIBS}
	glut32.lib
)