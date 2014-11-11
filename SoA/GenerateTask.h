///
/// GenerateTask.h
/// Seed of Andromeda
///
/// Created by Benjamin Arnold on 11 Nov 2014
/// Copyright 2014 Regrowth Studios
/// All Rights Reserved
///
/// Summary:
/// Implements the generate task for SoA chunk generation
///

#pragma once

#ifndef LoadTask_h__
#define LoadTask_h__

class Chunk;
struct LoadData;

// Represents A Chunk Load Task
struct GenerateTask {
public:
    // Chunk To Be Loaded
    Chunk* chunk;

    // Loading Information
    LoadData* loadData;

    // Initialize Task With Data
    GenerateTask(Chunk *ch = 0, LoadData *ld = 0) {
        chunk = ch;
        loadData = ld;
    }
};

#endif // LoadTask_h__