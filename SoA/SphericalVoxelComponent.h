///
/// SphericalVoxelComponent.h
/// Seed of Andromeda
///
/// Created by Benjamin Arnold on 5 Jan 2015
/// Copyright 2014 Regrowth Studios
/// All Rights Reserved
///
/// Summary:
/// Component for voxels mapped to a spherical world
///

#pragma once

#ifndef SphericalVoxelComponent_h__
#define SphericalVoxelComponent_h__

#include "IVoxelMapper.h"

class Camera;
class Chunk;
class ChunkIOManager;
class ChunkManager;
class IOManager;
class ParticleEngine;
class PhysicsEngine;
class PlanetGenData;
class SphericalTerrainData;
class SphericalTerrainGenerator;

namespace vorb {
    namespace voxel {
        class VoxelPlanetMapper;
    }
}
namespace vvox = vorb::core::voxel;

class SphericalVoxelComponent {
public:
    SphericalVoxelComponent();
    ~SphericalVoxelComponent();

    void init(const SphericalTerrainData* sphericalTerrainData, const IOManager* saveFileIom,
              const glm::dvec3 &gpos, vvox::VoxelMapData* startingMapData);

    void update(const Camera* voxelCamera);
    void getClosestChunks(glm::dvec3 &coord, Chunk **chunks);
    void endSession();

    inline ChunkManager* getChunkManager() { return m_chunkManager.get(); }
    inline PhysicsEngine* getPhysicsEngine() { return m_physicsEngine.get(); }

private:
    void destroyVoxels();
    void updatePhysics(const Camera* camera);

    //chunk manager manages and updates the chunk grid
    std::unique_ptr<ChunkManager> m_chunkManager = nullptr;
    std::unique_ptr<ChunkIOManager> m_chunkIo = nullptr;
    std::unique_ptr<PhysicsEngine> m_physicsEngine = nullptr;
    std::unique_ptr<ParticleEngine> m_particleEngine = nullptr;
    std::unique_ptr<SphericalTerrainGenerator> m_generator = nullptr;

    std::unique_ptr<vvox::VoxelPlanetMapper> m_voxelPlanetMapper = nullptr;

    PlanetGenData* m_planetGenData = nullptr;
    const SphericalTerrainData* m_sphericalTerrainData = nullptr;

    const IOManager* m_saveFileIom = nullptr;

    bool m_enabled = false;
};

#endif // SphericalVoxelComponent_h__