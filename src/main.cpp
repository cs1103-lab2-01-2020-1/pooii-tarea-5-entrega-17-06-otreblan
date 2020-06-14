// Observer
// Copyright © 2020 otreblan
//
// observer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// observer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with observer.  If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <sstream>

#include <readline/readline.h>
#include <readline/history.h>

#include <env.hpp>

int main()
{
	aru::Env env;

	while(char* line = readline("> "))
	{
		if(strlen(line) > 0)
		{
			add_history(line);

			std::istringstream is(line);
			std::string s_buf;

			if(std::getline(is, s_buf, ' '))
			{
				auto resu = env.action(s_buf, is);
				if(!resu.first)
					std::cerr << "\e[1;31mERROR\e[0m: ";
				std::cout << resu.second;
			}
		}

		free(line);
	}

	return 0;
}
