#include <iostream>
#include <vector>


//Построение матрицы
std::vector<std::vector<char>> assembling_v (int line, int column)
{
    std::vector<std::vector<char>> assembling(line, std::vector<char>(column));
    for(int idex = 0; idex < line; idex++)
    {
        for(int idex_c = 0; idex_c < column; idex_c++)
        {
            assembling[idex][idex_c] = '0';
        }
    }

    /*
     for(int limits_l = 0; limits_l<line; limits_l++)
     {
         for(int limits_c = 0; limits_c < column; limits_c++)
         {
             std::cout << assembling[limits_l][limits_c];
         }
         std::cout << std::endl;
     }
     */

    return assembling;
}

//Раставление мин
/*
std::vector<std::vector<char>> placement_min_in_vector
(std::vector<int> coordinate_min, std::vector<std::vector<char>> assembling)
{
    //std::vector<std::string> v_with_min;

    for(int idex = 0; idex < coordinate_min.size(); idex +=2)
    {
        assembling[coordinate_min[idex]][coordinate_min[idex]] = '*';
        assembling[coordinate_min[idex]][coordinate_min[idex+1]] = '*';
    }
    return assembling;
}
*/

std::vector<std::vector<char>> placement_min_in_vector
                            (std::vector<int> coordinate_min, std::vector<std::vector<char>> assembling)
{
    for(size_t idex = 0; idex < coordinate_min.size(); idex += 2)
    {
        size_t row = coordinate_min[idex];
        size_t col = coordinate_min[idex + 1];

        // Проверка границ
        if (row < assembling.size() && col < assembling[0].size()) {
            assembling[row][col] = '*';
        }
    }
    return assembling;
}

//расставление чисел
std::vector<std::vector<char>> placement_number (std::vector<std::vector<char>> matrix_whith_min)
{
    size_t size_line = matrix_whith_min.size();
    size_t size_column = matrix_whith_min[0].size();

    for(size_t index_line = 0; index_line != matrix_whith_min.size(); ++index_line)
    {
        for(size_t index_column = 0; index_column != matrix_whith_min[0].size(); ++index_column)
        {
            if (matrix_whith_min[index_line][index_column] == '*')
            {
                for(int i = -1; i <= 1; ++i)
                {
                    for(int j = -1; j <= 1; ++j)
                    {
                        size_t new_line = index_line + i;
                        size_t new_column = index_column + j;
                        
                        
                        if(new_line >= 0 && new_line < size_line &&
                            new_column >= 0 && new_column < size_column)
                        {
                            if (matrix_whith_min[new_line][new_column] != '*')
                            {
                                matrix_whith_min[new_line][new_column] += 1;
                            }
                        }
                        
                    }
                }
            }
        }
    }


return matrix_whith_min;
}




int  main()
{
    int line;
    int column;
    
    std::vector <int> coordinates; //= {1, 1, 2, 3,3,2};
    int coord;
    std::vector<std::vector<char>> assembling;

    std::cin >> line >> column;
    
    while (std::cin >> coord)
    {
        coordinates.push_back(coord);
    }


    assembling = placement_number(placement_min_in_vector(coordinates,assembling_v(line, column)));

    for(int limits_l = 0; limits_l<line; limits_l++)
    {
        for(int limits_c = 0; limits_c < column; limits_c++)
        {
            std::cout << assembling[limits_l][limits_c];
        }
        std::cout << std::endl;
    }


}