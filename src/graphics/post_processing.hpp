//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2011-2013 the SuperTuxKart-Team
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

#ifndef HEADER_POST_PROCESSING_HPP
#define HEADER_POST_PROCESSING_HPP

#include "IShaderConstantSetCallBack.h"
#include "S3DVertex.h"
#include "SMaterial.h"

#include <vector>

namespace irr
{
    namespace video { class IVideoDriver;   class ITexture; }
}
using namespace irr;

/** \brief   Handles post processing, eg motion blur
 *  \ingroup graphics
 */
class PostProcessing: public IReferenceCounted
{
private:
    video::SMaterial    m_material;

    /** Boost time, how long the boost should be displayed. This also
     *  affects the strength of the effect: longer boost time will
     *  have a stronger effect. */
    std::vector<float>  m_boost_time;

    bool m_any_boost;

    /** The center of blurring, in texture coordinates [0,1]).*/
    std::vector<core::vector2df> m_center;

    /** The center to which the blurring is aimed at, in [0,1]. */
    std::vector<core::vector2df> m_direction;

    struct Quad { video::S3DVertex v0, v1, v2, v3; };

    /** The vertices for the rectangle used for each camera. This includes
     *  the vertex position, normal, and texture coordinate. */
    std::vector<Quad> m_vertices;

    video::ITexture *m_areamap;

    u32 m_sunpixels;

    void setMotionBlurCenterY(const u32 num, const float y);

public:
                 PostProcessing(video::IVideoDriver* video_driver);
    virtual     ~PostProcessing();

    void         reset();
    /** Those should be called around the part where we render the scene to be post-processed */
    void         begin();
    void         update(float dt);

    /** Generate diffuse and specular map */
    void         renderSunlight();
    void         renderShadowedSunlight(const std::vector<core::matrix4> &sun_ortho_matrix, unsigned depthtex);

    void renderFog();
    void renderSSAO();
    void renderDiffuseEnvMap(const float *bSHCoeff, const float *gSHCoeff, const float *rSHCoeff);

    /** Blur the in texture */
    void renderGaussian3Blur(unsigned in_fbo, unsigned in_tex, unsigned tmp_fbo, unsigned tmp_tex, size_t inv_width, size_t inv_height);
    void renderGaussian6Blur(unsigned in_fbo, unsigned in_tex, unsigned tmp_fbo, unsigned tmp_tex, size_t width, size_t height);

    /** Render tex. Used for blit/texture resize */
    void renderPassThrough(unsigned tex);
    void applyMLAA();

    void renderMotionBlur(unsigned cam, unsigned in_rtt, unsigned out_fbo);
    void renderGlow(unsigned tex);

    /** Render the post-processed scene */
    void         render();

    /** Use motion blur for a short time */
    void         giveBoost(unsigned int cam_index);

    void         setSunPixels(const u32 in) { m_sunpixels = in; }
};

#endif // HEADER_POST_PROCESSING_HPP
