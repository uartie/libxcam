/*
 * data_types.h - data types in interface
 *
 *  Copyright (c) 2017 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: Wind Yuan <feng.yuan@intel.com>
 * Author: Yinhang Liu <yinhangx.liu@intel.com>
 */

#ifndef XCAM_INTERFACE_DATA_TYPES_H
#define XCAM_INTERFACE_DATA_TYPES_H

#include "xcam_utils.h"
#include "smartptr.h"

namespace XCam {

struct Rect {
    int32_t pos_x, pos_y;
    int32_t width, height;

    Rect () : pos_x (0), pos_y (0), width (0), height (0) {}
};

struct ImageCropInfo {
    uint32_t left;
    uint32_t right;
    uint32_t top;
    uint32_t bottom;

    ImageCropInfo () : left (0), right (0), top (0), bottom (0) {}
};

struct FisheyeInfo {
    float    center_x;
    float    center_y;
    float    wide_angle;
    float    radius;
    float    rotate_angle; // clockwise

    FisheyeInfo ()
        : center_x (0.0f), center_y (0.0f), wide_angle (0.0f)
        , radius (0.0f), rotate_angle (0.0f)
    {}
    bool is_valid () const {
        return wide_angle >= 1.0f && radius >= 1.0f;
    }
};

}

#endif //XCAM_INTERFACE_DATA_TYPES_H