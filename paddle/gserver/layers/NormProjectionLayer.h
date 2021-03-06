/* Copyright (c) 2016 Baidu, Inc. All Rights Reserve.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */


#pragma once

#include "NormLayer.h"
#include "paddle/math/Matrix.h"
#include <vector>

namespace paddle {

/**
 * @brief response normalization across feature maps
 * namely normalize in number of size_ channels 
 */
class CMRProjectionNormLayer : public ResponseNormLayer {
  size_t imgSizeH_, imgSizeW_;
  size_t outputH_, outputW_;

protected:
  bool blocked_;

public:
  explicit CMRProjectionNormLayer(const LayerConfig& config)
      : ResponseNormLayer(config) {}

  ~CMRProjectionNormLayer() {}

  size_t getSize();

  bool init(const LayerMap& layerMap, const ParameterMap& parameterMap);
  void forward(PassType passType);
  void backward(const UpdateCallback& callback = nullptr);
};
}  // namespace paddle
