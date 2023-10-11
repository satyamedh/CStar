//
// Created by satyamedh on 11/10/23.
//

#include <cmath>
#include <string>

#ifndef CSTAR_LOCATION_H
#define CSTAR_LOCATION_H

class location {
    public:
        int x{};
        int y{};
        bool not_set{};

        bool check_not_set() const;
        void set_location(int x, int y);
        double distance(location loc) const;
        bool operator==(const location& loc) const;
        std::string to_string() const;

        location(int x, int y, bool not_set);
};


#endif //CSTAR_LOCATION_H
