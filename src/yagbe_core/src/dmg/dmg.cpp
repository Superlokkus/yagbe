#include <yagbe_core/dmg/dmg.hpp>

namespace yagbe {
struct yagbe::dmg::impl {

};

dmg::dmg() : pimpl(std::make_unique<dmg::impl>()) {

}

dmg::~dmg() = default;

}
