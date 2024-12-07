#include <iostream>
#include <memory>

namespace changeable_array
{
    class Array final
    {
        private:
	    class ArrNode final
            {
                public:
                    int x_;
                    int y_;
		            std::shared_ptr<ArrNode> left_;
                    std::shared_ptr<ArrNode> right_;

                public:
                    ArrNode() : x_(0), y_(0) {};
                    ArrNode(int x, int y) : x_(x), y_(y) {};
                    ArrNode(const ArrNode& copy) 
                    {
                        x_ = copy.x_;
                        y_ = copy.y_;
                        left_ = copy.left_;
                        right_ = copy.right_;
		            };
                    
                    ArrNode(ArrNode&& rhs) 
                    {
                        x_ = rhs.x_;
                        y_ = rhs.y_;
			            std::swap(left_, rhs.left_);
                        std::swap(right_, rhs.right_);
		            };

                    bool operator==(const ArrNode& rhs) const 
                    {
                        if ((x_ == rhs.x_ && y_ == rhs.y_) && (left_ == rhs.left_ && right_ == rhs.right_)) return true;
                        return false;
		            };
		    
		            bool operator!=(const ArrNode& rhs) const {return !(*this == rhs);};

                    ArrNode& operator=(const ArrNode& rhs)
                    {
                        if (*this != rhs) {
                            x_ = rhs.x_;
                            y_ = rhs.y_;
                            left_ = rhs.left_;
                            right_ = rhs.right_;
                            return *this;
                        }
                        return *this;
		            }
		    
                    ArrNode& operator=(ArrNode&& rhs) 
                    {
                        x_ = rhs.x_;
                        y_ = rhs.y_;
                        std::swap(left_, rhs.left_);
                        std::swap(right_, rhs.right_);
                        return *this;
		            };

	    };

	    std::shared_ptr<ArrNode> first_;
        std::shared_ptr<ArrNode> last_;

        void Delete(std::shared_ptr<ArrNode>);
        std::shared_ptr<ArrNode> Moving(int);


        public:
            Array(int x, int y) : first_(new ArrNode), last_(new ArrNode)
            {
                first_->x_ = x;
                first_->y_ = y;
                first_->right_ = last_;
                last_->left_ = first_;
            };

            void PushBack(int, int);
            int GetFirstCoord(bool) const;
            int GetLastCoord(bool) const;
            int GetIndexCoord(bool, int) const;
            void DeleteFirst();
            void DeleteLast();
            void DeleteByIndex(int);

            int GetSecondCoord(bool); //for testing
            void DeleteSecond(); //for testing
            void Test(); //for testing
            void BackTest(); //for testing
            std::shared_ptr<ArrNode> MinMax(bool, bool);
    };


}
