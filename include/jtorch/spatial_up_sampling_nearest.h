//
//  spatial_up_sampling_nearest.h
//
//  Created by Jonathan Tompson on 1/27/15.
//

#pragma once

#include "jcl/math/int_types.h"
#include "jcl/math/math_types.h"
#include "jtorch/torch_data.h"
#include "jtorch/torch_stage.h"

namespace jtorch {

template <typename T>
class Tensor;

class SpatialUpSamplingNearest : public TorchStage {
 public:
  // Constructor / Destructor
  SpatialUpSamplingNearest(const int32_t scale);
  ~SpatialUpSamplingNearest() override;

  TorchStageType type() const override {
    return SPATIAL_UP_SAMPLING_NEAREST_STAGE;
  }
  std::string name() const override { return "SpatialUpSamplingNearest"; }
  void forwardProp(std::shared_ptr<TorchData> input) override;

  static std::unique_ptr<TorchStage> loadFromFile(std::ifstream& file);

 protected:
  uint32_t scale_;
  uint32_t out_dim_;
  std::unique_ptr<uint32_t[]> out_size_;

  void init(std::shared_ptr<TorchData> input);

  // Non-copyable, non-assignable.
  SpatialUpSamplingNearest(const SpatialUpSamplingNearest&) = delete;
  SpatialUpSamplingNearest& operator=(const SpatialUpSamplingNearest&) = delete;
};

};  // namespace jtorch
