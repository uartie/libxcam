/*
 * cv_image_deblurring.h - iterative blind deblurring
 *
 *  Copyright (c) 2016-2017 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: Andrey Parfenov <a1994ndrey@gmail.com>
 * Author: Wind Yuan <feng.yuan@intel.com>
 */

#ifndef XCAM_CV_FEATURE_DEBLURRING_H
#define XCAM_CV_FEATURE_DEBLURRING_H

#include "xcam_utils.h"
#include <base/xcam_common.h>
#include <base/xcam_buffer.h>
#include <dma_video_buffer.h>
#include <smartptr.h>
#include "xcam_obj_debug.h"
#include "image_file_handle.h"
#include "cv_base_class.h"
#include "cv_image_process_helper.h"
#include "cv_image_sharp.h"
#include "cv_edgetaper.h"
#include "cv_wiener_filter.h"

#include <ocl/cl_context.h>
#include <ocl/cl_device.h>
#include <ocl/cl_memory.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/ocl.hpp>

namespace XCam {

struct CVIDConfig {
    int iterations;            // number of iterations for IBD algorithm

    CVIDConfig (unsigned int _iterations = 50)
    {
        iterations = _iterations;
    }
};

class CVImageDeblurring : public CVBaseClass
{

public:
    explicit CVImageDeblurring ();

    void set_config (CVIDConfig config);
    CVIDConfig get_config ();

    void blind_deblurring (const cv::Mat &blurred, cv::Mat &deblurred, cv::Mat &kernel);

private:
    void blind_deblurring_one_channel (const cv::Mat &blurred, cv::Mat &kernel, int kernelSize, float noise_power);
    int estimate_kernel_size (const cv::Mat &blurred);
    void crop_border (cv::Mat &image);

    XCAM_DEAD_COPY (CVImageDeblurring);

    CVIDConfig                          _config;
    SmartPtr<CVImageProcessHelper>      _helper;
    SmartPtr<CVImageSharp>              _sharp;
    SmartPtr<CVEdgetaper>               _edgetaper;
    SmartPtr<CVWienerFilter>            _wiener;
};

}

#endif // XCAM_CV_IMAGE_DEBLURRING_H
