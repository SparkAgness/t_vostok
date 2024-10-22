#include <iostream>

namespace changeable_array
{
    class Array final
    {
        private:
	    class ArrNode final
            {
                private:
                    int* coords_;
		    ArrNode* left_;
                    ArrNode* right_;

                public:
                    ArrNode() : coords_{new int [2]} {*coords_ = 0; *(coords_ + 1) = 0; left_ = nullptr; right_ = nullptr;};
                    ArrNode(int x, int y) : coords_{new int [2]} {*coords_ = x, *(coords_ + 1) = y, left_ = nullptr; right_ = nullptr;};
                   
		    ~ArrNode() {delete [] coords_;};
	    };

        public:
    };
}
