/*
   Copyright (C) 2017  Statoil ASA, Norway.
   The file 'nex2ecl' is part of ERT - Ensemble based Reservoir Tool.

   ERT is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   ERT is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.

   See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html>
   for more details.
*/

#include <stdlib.h>
#include <string.h>

#include <ert/util/util.h>
#include <ert/util/vector.h>

#include <ert/ecl/ecl_kw.h>
#include <ert/ecl/ecl_sum.h>
#include <ert/ecl/smspec_node.h>



void create_ecl_sum(char *file_path) {

    std::stringstream ss;
    std::cout << ss.str() << std::endl;
    nex::NexusPlot plt = nex::load(ss.str());

    ss.erease(size(ss)-4,size(ss));
    ecl_sum_type *ecl_sum = nex::ecl_summary( ss, plt );
    ecl_sum_fwrite( ecl_sum );
    ecl_sum_free( ecl_sum );

}



int main(int argc, char **argv) {
    create_ecl_sum(argv[1]);
    exit(0);
}