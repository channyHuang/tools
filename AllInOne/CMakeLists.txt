cmake_minimum_required(VERSION 3.0)
set(target AllInOne)
set(CMAKE_PREFIX_PATH 
	"D:/Qt/Qt5.4.1/5.4/msvc2013_64_opengl"
	"E:/thirdLib/boost_1_56_0"
	"E:/thirdLib/OpenCV/opencv/build"
)

set(GL_DIR "E:/thirdLib/gl")
set(BOOST_INCLUDE_DIR "E:/thirdLib/boost_1_56_0")
set(BOOST_LIBRARY_DIR "E:/thirdLib/boost_1_56_0/lib64-msvc-12.0")
set(PCL_DIR "E:/thirdLib/PCL_1.7.2")
set(Eigen_DIR "E:/thirdLib/eigen-3.3.2") 
set(VTK_DIR "E:/thirdLib/VTK-7.0.0.rc1")
set(VTK_LIBRARY_DIR "E:/thirdLib/VTK-7.0.0.rc1/build/lib/Debug")

set(PCL_LIBRARIES 
pcl_common_debug.lib
pcl_features_debug.lib
pcl_filters_debug.lib
pcl_io_ply_debug.lib
pcl_io_debug.lib
pcl_kdtree_debug.lib
pcl_keypoints_debug.lib
pcl_octree_debug.lib
pcl_outofcore_debug.lib
pcl_people_debug.lib
pcl_recognition_debug.lib
pcl_registration_debug.lib
pcl_sample_consensus_debug.lib
pcl_search_debug.lib
pcl_segmentation_debug.lib
pcl_surface_debug.lib
pcl_tracking_debug.lib
pcl_visualization_debug.lib
)
set(VTK_LIBRARIES
vtkalglib-6.2-gd.lib
vtkalglib-6.2.lib
vtkChartsCore-6.2-gd.lib
vtkChartsCore-6.2.lib
vtkCommonColor-6.2-gd.lib
vtkCommonColor-6.2.lib
vtkCommonComputationalGeometry-6.2-gd.lib
vtkCommonComputationalGeometry-6.2.lib
vtkCommonCore-6.2-gd.lib
vtkCommonCore-6.2.lib
vtkCommonDataModel-6.2-gd.lib
vtkCommonDataModel-6.2.lib
vtkCommonExecutionModel-6.2-gd.lib
vtkCommonExecutionModel-6.2.lib
vtkCommonMath-6.2-gd.lib
vtkCommonMath-6.2.lib
vtkCommonMisc-6.2-gd.lib
vtkCommonMisc-6.2.lib
vtkCommonSystem-6.2-gd.lib
vtkCommonSystem-6.2.lib
vtkCommonTransforms-6.2-gd.lib
vtkCommonTransforms-6.2.lib
vtkDICOMParser-6.2-gd.lib
vtkDICOMParser-6.2.lib
vtkDomainsChemistry-6.2-gd.lib
vtkDomainsChemistry-6.2.lib
vtkexoIIc-6.2-gd.lib
vtkexoIIc-6.2.lib
vtkexpat-6.2-gd.lib
vtkexpat-6.2.lib
vtkFiltersAMR-6.2-gd.lib
vtkFiltersAMR-6.2.lib
vtkFiltersCore-6.2-gd.lib
vtkFiltersCore-6.2.lib
vtkFiltersExtraction-6.2-gd.lib
vtkFiltersExtraction-6.2.lib
vtkFiltersFlowPaths-6.2-gd.lib
vtkFiltersFlowPaths-6.2.lib
vtkFiltersGeneral-6.2-gd.lib
vtkFiltersGeneral-6.2.lib
vtkFiltersGeneric-6.2-gd.lib
vtkFiltersGeneric-6.2.lib
vtkFiltersGeometry-6.2-gd.lib
vtkFiltersGeometry-6.2.lib
vtkFiltersHybrid-6.2-gd.lib
vtkFiltersHybrid-6.2.lib
vtkFiltersHyperTree-6.2-gd.lib
vtkFiltersHyperTree-6.2.lib
vtkFiltersImaging-6.2-gd.lib
vtkFiltersImaging-6.2.lib
vtkFiltersModeling-6.2-gd.lib
vtkFiltersModeling-6.2.lib
vtkFiltersParallel-6.2-gd.lib
vtkFiltersParallel-6.2.lib
vtkFiltersParallelImaging-6.2-gd.lib
vtkFiltersParallelImaging-6.2.lib
vtkFiltersProgrammable-6.2-gd.lib
vtkFiltersProgrammable-6.2.lib
vtkFiltersSelection-6.2-gd.lib
vtkFiltersSelection-6.2.lib
vtkFiltersSMP-6.2-gd.lib
vtkFiltersSMP-6.2.lib
vtkFiltersSources-6.2-gd.lib
vtkFiltersSources-6.2.lib
vtkFiltersStatistics-6.2-gd.lib
vtkFiltersStatistics-6.2.lib
vtkFiltersTexture-6.2-gd.lib
vtkFiltersTexture-6.2.lib
vtkFiltersVerdict-6.2-gd.lib
vtkFiltersVerdict-6.2.lib
vtkfreetype-6.2-gd.lib
vtkfreetype-6.2.lib
vtkftgl-6.2-gd.lib
vtkftgl-6.2.lib
vtkGeovisCore-6.2-gd.lib
vtkGeovisCore-6.2.lib
vtkgl2ps-6.2-gd.lib
vtkgl2ps-6.2.lib
vtkhdf5-6.2-gd.lib
vtkhdf5-6.2.lib
vtkhdf5_hl-6.2-gd.lib
vtkhdf5_hl-6.2.lib
vtkImagingColor-6.2-gd.lib
vtkImagingColor-6.2.lib
vtkImagingCore-6.2-gd.lib
vtkImagingCore-6.2.lib
vtkImagingFourier-6.2-gd.lib
vtkImagingFourier-6.2.lib
vtkImagingGeneral-6.2-gd.lib
vtkImagingGeneral-6.2.lib
vtkImagingHybrid-6.2-gd.lib
vtkImagingHybrid-6.2.lib
vtkImagingMath-6.2-gd.lib
vtkImagingMath-6.2.lib
vtkImagingMorphological-6.2-gd.lib
vtkImagingMorphological-6.2.lib
vtkImagingSources-6.2-gd.lib
vtkImagingSources-6.2.lib
vtkImagingStatistics-6.2-gd.lib
vtkImagingStatistics-6.2.lib
vtkImagingStencil-6.2-gd.lib
vtkImagingStencil-6.2.lib
vtkInfovisCore-6.2-gd.lib
vtkInfovisCore-6.2.lib
vtkInfovisLayout-6.2-gd.lib
vtkInfovisLayout-6.2.lib
vtkInteractionImage-6.2-gd.lib
vtkInteractionImage-6.2.lib
vtkInteractionStyle-6.2-gd.lib
vtkInteractionStyle-6.2.lib
vtkInteractionWidgets-6.2-gd.lib
vtkInteractionWidgets-6.2.lib
vtkIOAMR-6.2-gd.lib
vtkIOAMR-6.2.lib
vtkIOCore-6.2-gd.lib
vtkIOCore-6.2.lib
vtkIOEnSight-6.2-gd.lib
vtkIOEnSight-6.2.lib
vtkIOExodus-6.2-gd.lib
vtkIOExodus-6.2.lib
vtkIOExport-6.2-gd.lib
vtkIOExport-6.2.lib
vtkIOGeometry-6.2-gd.lib
vtkIOGeometry-6.2.lib
vtkIOImage-6.2-gd.lib
vtkIOImage-6.2.lib
vtkIOImport-6.2-gd.lib
vtkIOImport-6.2.lib
vtkIOInfovis-6.2-gd.lib
vtkIOInfovis-6.2.lib
vtkIOLegacy-6.2-gd.lib
vtkIOLegacy-6.2.lib
vtkIOLSDyna-6.2-gd.lib
vtkIOLSDyna-6.2.lib
vtkIOMINC-6.2-gd.lib
vtkIOMINC-6.2.lib
vtkIOMovie-6.2-gd.lib
vtkIOMovie-6.2.lib
vtkIONetCDF-6.2-gd.lib
vtkIONetCDF-6.2.lib
vtkIOParallel-6.2-gd.lib
vtkIOParallel-6.2.lib
vtkIOParallelXML-6.2-gd.lib
vtkIOParallelXML-6.2.lib
vtkIOPLY-6.2-gd.lib
vtkIOPLY-6.2.lib
vtkIOSQL-6.2-gd.lib
vtkIOSQL-6.2.lib
vtkIOVideo-6.2-gd.lib
vtkIOVideo-6.2.lib
vtkIOXML-6.2-gd.lib
vtkIOXML-6.2.lib
vtkIOXMLParser-6.2-gd.lib
vtkIOXMLParser-6.2.lib
vtkjpeg-6.2-gd.lib
vtkjpeg-6.2.lib
vtkjsoncpp-6.2-gd.lib
vtkjsoncpp-6.2.lib
vtklibxml2-6.2-gd.lib
vtklibxml2-6.2.lib
vtkmetaio-6.2-gd.lib
vtkmetaio-6.2.lib
vtkNetCDF-6.2-gd.lib
vtkNetCDF-6.2.lib
vtkNetCDF_cxx-6.2-gd.lib
vtkNetCDF_cxx-6.2.lib
vtkoggtheora-6.2-gd.lib
vtkoggtheora-6.2.lib
vtkParallelCore-6.2-gd.lib
vtkParallelCore-6.2.lib
vtkpng-6.2-gd.lib
vtkpng-6.2.lib
vtkproj4-6.2-gd.lib
vtkproj4-6.2.lib
vtkRenderingAnnotation-6.2-gd.lib
vtkRenderingAnnotation-6.2.lib
vtkRenderingContext2D-6.2-gd.lib
vtkRenderingContext2D-6.2.lib
vtkRenderingContextOpenGL-6.2-gd.lib
vtkRenderingContextOpenGL-6.2.lib
vtkRenderingCore-6.2-gd.lib
vtkRenderingCore-6.2.lib
vtkRenderingFreeType-6.2-gd.lib
vtkRenderingFreeType-6.2.lib
vtkRenderingFreeTypeOpenGL-6.2-gd.lib
vtkRenderingFreeTypeOpenGL-6.2.lib
vtkRenderingGL2PS-6.2-gd.lib
vtkRenderingGL2PS-6.2.lib
vtkRenderingImage-6.2-gd.lib
vtkRenderingImage-6.2.lib
vtkRenderingLabel-6.2-gd.lib
vtkRenderingLabel-6.2.lib
vtkRenderingLIC-6.2-gd.lib
vtkRenderingLIC-6.2.lib
vtkRenderingLOD-6.2-gd.lib
vtkRenderingLOD-6.2.lib
vtkRenderingOpenGL-6.2-gd.lib
vtkRenderingOpenGL-6.2.lib
vtkRenderingVolume-6.2-gd.lib
vtkRenderingVolume-6.2.lib
vtkRenderingVolumeOpenGL-6.2-gd.lib
vtkRenderingVolumeOpenGL-6.2.lib
vtksqlite-6.2-gd.lib
vtksqlite-6.2.lib
vtksys-6.2-gd.lib
vtksys-6.2.lib
vtktiff-6.2-gd.lib
vtktiff-6.2.lib
vtkverdict-6.2-gd.lib
vtkverdict-6.2.lib
vtkViewsContext2D-6.2-gd.lib
vtkViewsContext2D-6.2.lib
vtkViewsCore-6.2-gd.lib
vtkViewsCore-6.2.lib
vtkViewsInfovis-6.2-gd.lib
vtkViewsInfovis-6.2.lib
vtkzlib-6.2-gd.lib
vtkzlib-6.2.lib

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

project(${target})

find_package(Boost REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(OpenCV REQUIRED)
find_package(CUDA REQUIRED)

file(GLOB HEADERS "*.h")
file(GLOB SOURCES "*.cpp")
file(GLOB UIS "*.ui")
file(GLOB QRCS "*.qrc")

include_directories(${target}
	${GL_DIR}	
	${Eigen_DIR}
	${BOOST_INCLUDE_DIR}
	${PCL_DIR}/include/pcl-1.7
	${PCL_DIR}/3rdParty/VTK/include/vtk-6.2
	${VTK_DIR}
	${VTK_DIR}/GUISupport/Qt
	${VTK_DIR}/Interaction/Style
	${VTK_DIR}/Rendering/OpenGL2
	${VTK_DIR}/build/GUISupport/Qt
	${VTK_DIR}/build/Interaction/Style
	${VTK_DIR}/build/Rendering/OpenGL2
	${OpenCV_INCLUDE_DIRS}
	${CUDA_INCLUDE_DIRS}
)

link_directories(${target}
	${BOOST_LIBRARY_DIR}
	${PCL_DIR}/lib
	${PCL_DIR}/3rdParty/VTK/lib
	${VTK_LIBRARY_DIR}
)


# Dont propogate host flags into CUDA environment.
#set(CUDA_PROPAGATE_HOST_FLAGS off)

# Generate code for 2.0 and 3.0 CUDA compute architectures (TODO: Verify this works)
#set(CUDA_NVCC_FLAGS "-use_fast_math -gencode arch=compute_30,code=sm_30 -gencode arch=compute_20,code=sm_20" )	
	
#cuda_add_executable(${target}
#	${HEADERS}
#	${SOURCES}
#	)

QT5_WRAP_CPP(MISTUDIO_HEADERS_MOC ${HEADERS})
QT5_WRAP_UI(qt_files ${UIS})
QT5_ADD_RESOURCES(MISTUDIO_QRC_RCC ${QRCS})

add_executable(${target}
	${SOURCES}
	${MISTUDIO_HEADERS_MOC}
	${MISTUDIO_QRC_RCC}	
	${qt_files}
)

target_link_libraries(${target}
	Qt5::Gui
	Qt5::Widgets
	Qt5::Core
	Qt5::OpenGL
	glu32
	opengl32
	${PCL_LIBRARIES}
	${VTK_LIBRARIES}
	${OpenCV_LIBS}
)