#ifndef ERROR_CHEAKING_FILM
#define ERROR_CHEAKING_FILM

class ProgramData;

class ErrorCheakingFilm {
public:
    void cheak_all_error_film(ProgramData* program_data);
    void cheak_user_in(ProgramData* program_data);
    void cheak_type_of_user(ProgramData* program_data);
};
#endif