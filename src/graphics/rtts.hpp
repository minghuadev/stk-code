//  SuperTuxKart - a fun racing game with go-kart
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef HEADER_RTTS_HPP
#define HEADER_RTTS_HPP

namespace irr {
    namespace video {
        class ITexture;
    };
};

using irr::video::ITexture;

enum TypeRTT
{
    RTT_TMP1 = 0,
    RTT_TMP2,
    RTT_TMP3,
    RTT_TMP4,
    RTT_NORMAL_AND_DEPTH,
    RTT_COLOR,
    RTT_LOG_LUMINANCE,

    RTT_HALF1,
    RTT_HALF2,

    RTT_QUARTER1,
    RTT_QUARTER2,
//    RTT_QUARTER3,
//    RTT_QUARTER4,

    RTT_EIGHTH1,
    RTT_EIGHTH2,

//    RTT_SIXTEENTH1,
//    RTT_SIXTEENTH2,

    RTT_SSAO,

//    RTT_COLLAPSE,
//    RTT_COLLAPSEH,
//    RTT_COLLAPSEV,
//    RTT_COLLAPSEH2,
//    RTT_COLLAPSEV2,
//    RTT_WARPH,
//    RTT_WARPV,

//    RTT_HALF_SOFT,

    RTT_DISPLACE,
    RTT_MLAA_COLORS,

    RTT_BLOOM_1024,
    RTT_BLOOM_512,
    RTT_TMP_512,
    RTT_BLOOM_256,
    RTT_TMP_256,
    RTT_BLOOM_128,
    RTT_TMP_128,

    RTT_COUNT
};


enum TypeFBO
{
    FBO_SSAO,
    FBO_NORMAL_AND_DEPTHS,
    FBO_COMBINED_TMP1_TMP2,
    FBO_COLORS,
    FBO_LOG_LUMINANCE,
    FBO_MLAA_COLORS,
    FBO_TMP1_WITH_DS,
    FBO_TMP2_WITH_DS,
    FBO_TMP4,
    FBO_HALF1,
    FBO_HALF2,
    FBO_QUARTER1,
    FBO_QUARTER2,
    FBO_EIGHTH1,
    FBO_EIGHTH2,
    FBO_DISPLACE,
    FBO_BLOOM_1024,
    FBO_BLOOM_512,
    FBO_TMP_512,
    FBO_BLOOM_256,
    FBO_TMP_256,
    FBO_BLOOM_128,
    FBO_TMP_128,
    FBO_COUNT
};

class RTT
{
public:
    RTT();
    ~RTT();

    unsigned getShadowFBO() const { return shadowFBO; }
    unsigned getShadowDepthTex() const { return shadowDepthTex; }

    unsigned getDepthStencilTexture() const { return DepthStencilTexture; }
    unsigned getRenderTarget(enum TypeRTT target) const { return RenderTargetTextures[target]; }
    unsigned getFBO(enum TypeFBO fbo) { return FrameBuffers[fbo]; }
private:
    unsigned RenderTargetTextures[RTT_COUNT], FrameBuffers[FBO_COUNT];
    unsigned DepthStencilTexture;

    unsigned shadowFBO, shadowColorTex, shadowDepthTex;
};

#endif

