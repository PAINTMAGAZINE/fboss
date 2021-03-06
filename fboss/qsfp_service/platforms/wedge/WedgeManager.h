#pragma once

#include <boost/container/flat_map.hpp>

#include "fboss/lib/usb/WedgeI2CBus.h"
#include "fboss/qsfp_service/platforms/wedge/WedgeI2CBusLock.h"
#include "fboss/qsfp_service/TransceiverManager.h"

namespace facebook { namespace fboss {
class WedgeManager : public TransceiverManager {
 public:
  WedgeManager();
  ~WedgeManager() override {}
  void initTransceiverMap() override;
  void getTransceiversInfo(std::map<int32_t, TransceiverInfo>& info,
    std::unique_ptr<std::vector<int32_t>> ids) override;
  void customizeTransceiver(int32_t idx, cfg::PortSpeed speed) override;

  int getNumQsfpModules() override {
    return 16;
  }

 private:
  // Forbidden copy constructor and assignment operator
  WedgeManager(WedgeManager const &) = delete;
  WedgeManager& operator=(WedgeManager const &) = delete;
 protected:
  virtual std::unique_ptr<BaseWedgeI2CBus> getI2CBus();
  std::unique_ptr<WedgeI2CBusLock> wedgeI2CBusLock_;
};
}} // facebook::fboss
