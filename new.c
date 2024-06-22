
void PasteAvValue(byte* begin, int pastes_row, int paste_place, int vals_time)
{
    *(begin + begin*pastes_row + paste_place) = vals_time;
};
