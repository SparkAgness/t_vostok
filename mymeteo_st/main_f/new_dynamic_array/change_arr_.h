#include <iostream>
#include <memory>

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
                    ArrNode(const ArrNode& copy) 
                    {
                        coords_ = new int [2] {*(copy.coords_), *(copy.coords_ + 1)};
                        left_ = copy.left_;
                        right_ = copy.right_;
		            };
                    ArrNode(ArrNode&& rhs) 
                    {
                        coords_ = new int [2] {*(rhs.coords_), *(rhs.coords_ + 1)};
			            std::swap(left_, rhs.left_);
                        std::swap(right_, rhs.right_);
		            };
                    ArrNode(int x, int y, ArrNode* prev, ArrNode* next) // for pushback method
                    {
                        coords_ = new int [2] {*coords_ = x, *(coords_ + 1) = y};
                        left_ = nullptr;
			            right_ = next;
		            };
		            ~ArrNode() {delete [] coords_;};

                    bool operator==(const ArrNode& rhs) const 
                    {
                        if ((*(this->coords_) == *(rhs.coords_)) && (*(this->coords_ + 1) == *(rhs.coords_ + 1)) && this->left_ == rhs.left_ && this->right_ == rhs.right_) return true;
                        return false;
		            };
		    
		            bool operator!=(const ArrNode& rhs) const {return !(*this == rhs);};

                    ArrNode& operator=(const ArrNode& rhs)
                    {
                        if (*this != rhs) {
                            coords_ = new int[2] {*(rhs.coords_), *(rhs.coords_ + 1)};
                            left_ = rhs.left_;
                            right_ = rhs.right_;
                            return *this;
                        }
                        return *this;
		            }
		    
                    ArrNode& operator=(ArrNode&& rhs) 
                    {
                        *(coords_) = *(rhs.coords_);
                        *(coords_ + 1) = *(rhs.coords_ + 1);
                        std::swap(left_, rhs.left_);
                        std::swap(right_, rhs.right_);
                        return *this;
		            };

                    void SetBackLink(ArrNode* left)
                    {
                        left_ = left;
                    };

                    void SetForwardLink(ArrNode* right)
                    {
                        right_ = right;
                    };

                    ArrNode* GetLink(bool forward = true)
                    {
                        if (forward) return right_;
                        return left_;
                    };

                    void SetCoord(int cx, int cy)
                    {
                        *coords_ = cx;
                        *(coords_ + 1) = cy;
                    };
                    
                    int GetCoord_(bool x) const
                    {
                        if (x) return *coords_;
                        return *(coords_ + 1);
                    };
	    };

	    ArrNode first_;
        ArrNode last_;

        public:
            Array(int x, int y) : first_(x, y), last_(0, 0) 
            {
                first_.SetForwardLink(&last_);
                last_.SetBackLink(&first_);
            };

            void PushBack(int, int);
            int GetFirstCoord(bool) const;
            int GetLastCoord(bool) const;
    };


}
