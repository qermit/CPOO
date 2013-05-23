/*
 * CodebookModel.h
 *
 *  Created on: 14-04-2013
 *      Author: tolkjen
 */

#ifndef CODEBOOKMODEL_H_
#define CODEBOOKMODEL_H_

#include <list>
#include <opencv2/opencv.hpp>
#include <opencv/cvaux.h>
#include <opencv/cxmisc.h>
#include <opencv/highgui.h>

#include "BackgroundModel.h"

using namespace std;
#define CHANNELS 3

class CodebookModel: public BackgroundModel {
/**
* The enumeration of space dimension
*/
    typedef struct codebook_element {
         /// Wskaźnik do następnego elementu
        struct codebook_element* next;
        /// last update
        int t_last_update;
        int stale;
        uchar boxMin[3];
        uchar boxMax[3];
        uchar learnMin[3];
        uchar learnMax[3];
    } codebook_element;
public:
	CodebookModel();
	virtual ~CodebookModel();

	virtual void insert(IplImage *rawFrame);
	virtual Mat& resultingFrame();
	virtual IplImage* resultingCap();
	virtual bool useCapture();

private:
    codebook_element * new_element();
    void remove_element(codebook_element *elem);

    void codebookUpdate();
    void codebookClearStale(int staleThresh);
    int codebookDiff();
    
    IplImage *ImaskCodeBook, *ImaskCodeBookCC;
    IplImage* yuvImage;
    int c, nframes;

    int nframes_to_learn;

    /* parametry do modelu*/
    int t;
    CvSize size;
    uchar cbBounds[3];
    uchar modMin[3];
    uchar modMax[3];
    /* do przechowywania elementow zaalokowanych wprzod */
    codebook_element *tmp_elem; /// elementy zaalokowane wprzod
    int tmp_elems_free; /// liczba zaalokowanych w przod elementow
    codebook_element** cbmap; /// tablica codebook, dla kazdego pixela
};

#endif /* HISTOGRAMMODEL_H_ */
