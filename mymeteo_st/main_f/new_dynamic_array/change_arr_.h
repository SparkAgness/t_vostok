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
		            std::shared_ptr<ArrNode> left_;
                    std::shared_ptr<ArrNode> right_;

                public:
                    ArrNode() : coords_{new int [2]} {*coords_ = 0; *(coords_ + 1) = 0; std::shared_ptr<ArrNode> left_; std::shared_ptr<ArrNode> right_;};
                    ArrNode(int x, int y) : coords_{new int [2]} {*coords_ = x, *(coords_ + 1) = y; std::shared_ptr<ArrNode> left_; std::shared_ptr<ArrNode> right_;};
                    ArrNode(const ArrNode& copy) 
                    {
                        coords_ = new int [2] {*(copy.coords_), *(copy.coords_ + 1)};
                        left_ = copy.left_;
                        right_ = copy.right_;
		            };
                    ArrNode(int x, int y, const ArrNode& left)
                    {
                        *coords_ = x;
                        *(coords_ + 1) = y;
                        left_ = std::make_shared<ArrNode>(left);
                    };
                    ArrNode(ArrNode&& rhs) 
                    {
                        coords_ = new int [2] {*(rhs.coords_), *(rhs.coords_ + 1)};
			            std::swap(left_, rhs.left_);
                        std::swap(right_, rhs.right_);
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

                    void SetBackLink(ArrNode& left)
                    {
                        left_ = std::make_shared<ArrNode>(left);
                    };

                    void SetForwardLink(ArrNode& right)
                    {
                        right_ = std::make_shared<ArrNode>(right);
                    };

                    std::shared_ptr<ArrNode> GetLink(bool forward = true)
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
                //ArrNode first_(x, y);
                //ArrNode last_;
                ArrNode& first = first_;
                ArrNode& last = last_;
                first_.SetForwardLink(last);
                last_.SetBackLink(first);
            };

            void PushBack(int, int);
            int GetFirstCoord(bool) const;
            int GetLastCoord(bool) const;
            int GetIndexCoord(bool, int);
            int TestLeftRight();

    };


}
