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

#include <string_view>
#include <string>

namespace aru
{

class Notifier;

class User
{
private:
	enum class notify_type
	{
		parking,
		tables
	};

	void notify(Notifier& notifier, notify_type type);
	friend class Notifier;

public:
	std::string name;

	User(std::string_view name);
	User() = default;
	virtual ~User() = default;
};
};
