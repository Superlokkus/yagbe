#ifndef YAGBE_DMG_HPP
#define YAGBE_DMG_HPP

#include <memory>

namespace yagbe {

class dmg final {
public:
    dmg();

    ~dmg();

private:
    struct impl;
    std::unique_ptr<impl> pimpl;
};

}
#endif //YAGBE_DMG_HPP
