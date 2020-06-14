// Observer
// Copyright © 2019-2020 otreblan
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

int main()
{
	while(char* line = readline("> "))
	{
		if(strlen(line) > 0)
		{
			add_history(line);

			std::istringstream is(line);
			std::string s_buf;

			for(int i = 0; std::getline(is, s_buf, ' '); ++i)
			{
				std::cout << s_buf << '\n';
			}
		}

		free(line);
	}

	return 0;
}
