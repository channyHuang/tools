#ifndef OTHERS_H
#define OTHERS_H

//read sensor data
extern int readSensorData();

//silhouette to model
extern void silhouetteToModel();

//model refine, using ICP
extern void refineModel();

//refine silhouette
extern void refineSilhouette();

#endif