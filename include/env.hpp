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

#pragma once

#include <string>

namespace aru
{
class Env
{
private:
	std::string current_user;

	void login(std::string_view new_user);
	void logout();
public:
	Env() = default;
	virtual ~Env() = default;

	/// Print help
	void help();
};
};
