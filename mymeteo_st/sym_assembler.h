		//strings 62, 73, 84 maybe are wrong!! retest them
		//to find nested classes and clear it 
#ifndef SYMBASSEMBLY
#define SYMBASSEMBLY

#include "Change_Arr.h"
#include <string>

#define X_MIDDLE 14
#define Y_MIDDLE 13

class Symbol final
{
    private:
        Changeable_Array figure_kit_;
        int offset_;//means sequence of symbol at display

        class Symbol_Part
        {
            private:

            protected:
                virtual void Rotate_AgainstCW(int) = 0;
                virtual void Fig_Creater() = 0;
                virtual void Mirror(bool, bool) = 0;
            public:
                Symbol_Part(int side) : coords_(0, 0), side_(side) {};
                virtual ~Symbol_Part();
        };

        class Corner : protected Symbol_Part final
        {
            private:
                Changeable_Array coords_;
                int side_;
                int sum_offset_; //consists of this->offset + inside offset (by default is 7)
            protected:
                void Rotate_AgainstCW(int) override;//ok
                void Fig_Creater() override;//ok
            public:
            Corner(int side = 4, in_offset = 7) : coords_(0, 0), side_(side), sum_offset_(in_offset + this->offset_) {};
            void DownCorner();
        };

        class Up_QuartCircle : protected Symbol_Part final
        {
            private:
                Changeable_Array coords_;
                int sum_offset_;
                void Mirroring(bool hor, bool vert)
                {
                    int arr_lengh = coord_.GetLenght();
                    if (hor && !vert) {
                        for (int i = 0; i < arr_lengh; ++i) {
                        int val = *(coord_.CoordValues(i));
                        coord_.ChangeMember(i, X_MIDDLE*2 - val);}
                    } else if (!hor && vert) {
                        for (int i = 0; i < arr_lengh; ++i) {
                        int val = *(coord_.CoordValues(i) + 1);
                        coord_.ChangerMember(i, true, 2*(Y_MIDDLE + 1) - val);}
                   } else {throw Wrong_Up_QuartCircle() }//EXCEPTION
		};
            public:
                Up_QuartCircle(int in_offset = 7) : coords_(0, 0), sum_offset_(in_offset + this->offset_) {};
                void Fig_Creater() override;//ok
                void Mirror(bool, bool) override; //ok, calls with exceptions
        };

        class Central_Point : protected Symbol_Part final
        {
            private:
                Changeable_Array coords_;
                int sum_offset_;
            public:
                Central_Point(int in_offset = X_MIDDLE - 1) : coords_(0, 0), sum_offset_(in_offset + this->offset_) {};
            protected:
                void Fig_Creater() override;
        };

        class Down_QuartCircle : protected Symbol_Part final
	{
            private:
                Changeable_Array coords_;
                int sum_offset_;
	    public:
                Down_QuartCircle(int in_offset = 7) : coords_(0, 0), sum_offset_(in_offset + this->offset_) {};
                void Mirror(bool, bool) override;
	};


    public:
        Symbol(int offset) : figure_kit_(0, 0), offset_(offset) {};

};

#endif
