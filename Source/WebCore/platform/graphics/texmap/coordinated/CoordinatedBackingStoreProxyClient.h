/*
 Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies)
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Library General Public
 License as published by the Free Software Foundation; either
 version 2 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Library General Public License for more details.
 
 You should have received a copy of the GNU Library General Public License
 along with this library; see the file COPYING.LIB.  If not, write to
 the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 Boston, MA 02110-1301, USA.
 */

#pragma once

#if USE(COORDINATED_GRAPHICS)

namespace WebCore {
class CoordinatedTileBuffer;
class GraphicsContext;
class SurfaceUpdateInfo;

class CoordinatedBackingStoreProxyClient {
public:
    virtual ~CoordinatedBackingStoreProxyClient() = default;
    virtual void tiledBackingStoreHasPendingTileCreation() = 0;

    virtual void createTile(uint32_t tileID, float) = 0;
    virtual void updateTile(uint32_t tileID, const IntRect&, const IntRect&, Ref<CoordinatedTileBuffer>&&) = 0;
    virtual void removeTile(uint32_t tileID) = 0;
};

} // namespace WebCore

#endif // USE(COORDINATED_GRAPHICS)
