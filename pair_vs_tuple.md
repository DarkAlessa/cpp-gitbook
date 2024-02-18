std::tuple : มี element ได้หลาย element
std::pair  : คือ tuple ที่มีได้แค่ 2 elements

// Tuple
		std::tuple<std::string, std::string, int> girl = {"Lalisa", "Manoban", 25};
		std::cout << std::get<0>(girl) << " " << std::get<1>(girl) << ", " << std::get<2>(girl) << '\n';

// Pair
    std::pair<std::string, int> girl = {"Lalisa Manoban", 25};
    std::cout << girl.first << ", " << girl.second ;