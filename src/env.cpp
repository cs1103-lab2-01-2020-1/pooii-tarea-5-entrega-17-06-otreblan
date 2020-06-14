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

#include <string_view>
#include <iostream>
#include <sstream>

#include <env.hpp>

void aru::Env::help()
{
	std::cout << "TODO: help\n";
}

bool aru::Env::action(std::string_view str, std::istream& is)
{
	auto it = action_map.find(str);

	if(it == action_map.end())
		return false;

	it->second(*this, is);
	return true;
}

void aru::Env::login(std::string_view new_user)
{
	if(users.find((std::string)new_user) == users.end())
		return;

	std::shared_ptr<User> user(new User(new_user));
	users[(std::string)new_user] = user;

	current_user = *user;
}

void aru::Env::logout()
{
	current_user.reset();
}

const std::unordered_map<std::string_view,
	std::function<void(aru::Env&, std::istream&)>> aru::Env::action_map =
{
	{
		"help",
		[](Env& env, std::istream& is)
		{
			env.help();

			std::string s_buf;
			while(std::getline(is, s_buf, ' ')){}
		}
	}
};
