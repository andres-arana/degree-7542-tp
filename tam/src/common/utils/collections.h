#ifndef __COMMON__UTILS__COLLECTIONS_H_INCLUDED__
#define __COMMON__UTILS__COLLECTIONS_H_INCLUDED__

#include <algorithm>

namespace common {
	namespace utils {
		template<typename T>
		void DeletePointer(T *element) {
			delete element;
		}

		template<typename T>
		void DeleteAndClearElements(T &container) {
			typedef typename T::iterator iterator;
			for (iterator it = container.begin(); it != container.end(); ++it) {
				delete *it;
			}

			container.clear();
		}
	}
}

#endif
