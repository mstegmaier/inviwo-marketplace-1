/*********************************************************************************
 *
 * Inviwo - Interactive Visualization Workshop
 *
 * Copyright (c) 2016-2021 Inviwo Foundation
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************************/
#pragma once

#include <modules/animation/animationmoduledefine.h>
#include <inviwo/core/common/inviwo.h>

#include <inviwo/core/util/factory.h>
#include <modules/animation/interpolation/interpolation.h>

#include <modules/animation/factories/interpolationfactoryobject.h>

namespace inviwo {
namespace animation {

class IVW_MODULE_ANIMATION_API InterpolationFactory
    : public StandardFactory<Interpolation, InterpolationFactoryObject> {
public:
    InterpolationFactory() = default;
    virtual ~InterpolationFactory() = default;

    using StandardFactory<Interpolation, InterpolationFactoryObject>::create;

    template <typename Keyframe>
    std::vector<InterpolationFactoryObject*> getSupportedInterpolations() const {
        std::vector<InterpolationFactoryObject*> interps;
        for (auto interp : map_) {
            if (dynamic_cast<InterpolationFactoryObjectKeyframe<Keyframe>*>(interp.second)) {
                interps.push_back(interp.second);
            }
        }
        return interps;
    }
};

}  // namespace animation
}  // namespace inviwo
