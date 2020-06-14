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

#include <string.h>

#include <readline.hpp>

// https://thoughtbot.com/blog/tab-completion-in-gnu-readline

const char* commands[] =
{
	"help",
	"login",
	"logout",
	"park-register",
	"park-unregister",
	"table-register",
	"table-unregister",
	nullptr
};

void initialize_readline()
{
	rl_readline_name = "observer";
	rl_attempted_completion_function = observer_completion;
}

char** observer_completion(const char* text, int start, int)
{
	return start == 0 ? rl_completion_matches(text, command_generator): nullptr;
}

char* command_generator(const char* text, int state)
{
	thread_local static int list_index, len;
	const char* name;

	if(!state)
	{
		list_index = 0;
		len = strlen(text);
	}

	while((name = commands[list_index++]))
	{
		if(strncmp(name, text, len) == 0)
			return strdup(name);
	}

	return nullptr;
}
