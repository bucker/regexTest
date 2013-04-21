#ifndef REGEXP_H
#define REGEXP_H

class regexp
{
    public:
        regexp();
        virtual ~regexp();
        int matchstar(int, char*, char*);
        int matchhere(char*, char*);
        int match(char*, char*);
    protected:
    private:
};

#endif // REGEXP_H
