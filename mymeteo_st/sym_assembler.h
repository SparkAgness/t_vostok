		//strings 62, 73, 84 maybe are wrong!! retest them
		//to find nested classes and clear it 
#ifndef SYMBASSEMBLY
#define SYMBASSEMBLY

#include "Change_Arr.h"
#include <string>
#include "Errors.h"

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
                virtual ~Symbol_Part();
        };

        class Corner final : protected Symbol_Part
        {
            private:
                Changeable_Array coords_;
                Symbol& parent_;
                int side_;
                int sum_offset_; //consists of this->offset + inside offset (by default is 7)
            protected:
                void Rotate_AgainstCW(int) override;//ok
                void Fig_Creater() override;//ok
            public:
            Corner(Symbol& parent, int side = 4, int in_offset = 7) : coords_(0, 0), parent_(parent), side_(side), sum_offset_(in_offset) {sum_offset_ += parent.offset_;};
            void DownCorner();
        };

        class Up_QuartCircle final : protected Symbol_Part
        {
            private:
                Changeable_Array coords_;
                Symbol& parent_;
                int sum_offset_;
                void Mirroring(bool hor, bool vert)
                {
                    int arr_lengh = coords_.GetLenght();
                    if (hor && !vert) {
                        for (int i = 0; i < arr_lengh; ++i) {
                        int val = *(coords_.CoordValues(i));
                        coords_.ChangeMember(i, X_MIDDLE*2 - val);}
                    } else if (!hor && vert) {
                        for (int i = 0; i < arr_lengh; ++i) {
                        int val = *(coords_.CoordValues(i) + 1);
                        coords_.ChangeMember(i, true, 2*(Y_MIDDLE + 1) - val);}
                   } else {throw Wrong_Up_QuartCircle(); }//EXCEPTION
		};
            public:
                Up_QuartCircle(Symbol& parent, int in_offset = 7) : coords_(0, 0), sum_offset_(in_offset), parent_(parent) {sum_offset_ += parent_.offset_;};
                void Fig_Creater() override;//ok
                void Mirror(bool, bool) override; //ok, calls with exceptions
        };

        class Central_Point final : protected Symbol_Part
        {
            private:
                Changeable_Array coords_;
                Symbol& parent_;
                int sum_offset_;
            public:
                Central_Point(Symbol& parent, int in_offset = X_MIDDLE - 1) : coords_(0, 0), sum_offset_(in_offset), parent_(parent) {sum_offset_ += parent_.offset_;};
            protected:
                void Fig_Creater() override;
        };

        class Down_QuartCircle final : protected Symbol_Part
	{
            private:
                Changeable_Array coords_;
                Symbol& parent_;
                int sum_offset_;
	    public:
                Down_QuartCircle(Symbol& parent, int in_offset = 7) : coords_(0, 0), sum_offset_(in_offset), parent_(parent) {sum_offset_ += parent_.offset_;};
                void Mirror(bool, bool) override;
	};

        class Vertical_Ln final : protected Symbol_Part
	{
            private:
                Changeable_Array coords_;
                Symbol& parent_;
                int sum_offset_;
            public:
                Vertical_Ln(Symbol& parent, int in_offset = X_MIDDLE) : coords_(0, 0), sum_offset_(in_offset), parent_(parent) {sum_offset_ += parent_.offset_;}
                void Fig_Creater() override;
                void Seven_Creater();
	};

        class Horizontal_Ln final : protected Symbol_Part
        {
            private:
                Changeable_Array coords_;
                Symbol& parent_;
                int sum_offset_;
            public:
                Horizontal_Ln(Symbol& parent, int in_offset = 7) : coords_(0, 0), sum_offset_(in_offset), parent_(parent) {sum_offset_ += parent_.offset_;};
            protected:
                void FigCreater() override;
        }

    public:
        Symbol(int offset) : figure_kit_(0, 0), offset_(offset) {};

};

#endif
