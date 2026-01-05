#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <optional>
#include <cinttypes>
#include <algorithm>

namespace choicesort {

    [[nodiscard]]
    uint32_t find_min_index(const std::vector<uint32_t>& v) {
        uint32_t min_index = 0;
        for (uint32_t i = 1; i < v.size(); i++) {
            if (v[i] < v[min_index]) {
                min_index = i;
            }
        }
        return min_index;
    }

    [[nodiscard]]
    std::vector<uint32_t> sort(const std::vector<uint32_t>& v) {
        if (v.empty()) return std::vector<uint32_t>();
        std::vector<uint32_t> result;
        std::vector<uint32_t> temp = v;

        result.reserve(v.size());

        for (uint32_t i = 0; i < v.size(); i++) {
            uint32_t min_index = find_min_index(temp);
            result.push_back(temp[min_index]);
            temp.erase(temp.begin() + min_index);
        }

        return result;

    }

}