/*
 * ManageDatabase.h
 *
 *  Created on: 13 de oct. de 2016
 *      Author: galvez
 */

#ifndef MANAGEDATABASE_H_
#define MANAGEDATABASE_H_

#include "Types.h"

#undef NUM_THREAD_FOR_LOADING
#define NUM_THREAD_FOR_LOADING 32
#define CHUNK_SEQ_SIZE 2000

typedef struct _SequencesChunk {
	SequenceDemultiplexed chunkSequences[CHUNK_SEQ_SIZE];
	struct _SequencesChunk * ptrNext;
} SequencesChunk;

typedef struct {
	SequencesChunk * headerChunk;
	int numSequences;
} SequencesList;

void initSequenceList(SequencesList *sl);
void * addSequence(SequencesList *sl, SequenceDemultiplexed * s);

////
typedef struct {
	int id;
	char *bulkFile;
	uint64_t first;
	uint64_t last;
	SequencesList ret;
	char * retBulkData;
} LoaderThreadParameters;

void loadDatabase(char * filename);
void * loadStep1(void * vparams);

#endif /* MANAGEDATABASE_H_ */
