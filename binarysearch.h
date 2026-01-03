#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <optional>


namespace bs {

    [[nodiscard]]
    std::optional<uint32_t> binary_search(const std::vector<uint32_t>& v, uint32_t e) {
        if (v.empty()) return std::nullopt;

        uint32_t start = 0;
        uint32_t end = v.size() - 1;

        uint32_t mid = 0;

        while(start <= end) {
            mid = start + (end - start) / 2; // (start + end) / 2 == start + (end - start) / 2
            if (v[mid] == e) {
                return mid;
            } else if (v[mid] > e) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return std::nullopt;
    }

}