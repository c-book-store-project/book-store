int instr(void)
{
    printf("\n***************\n");
    printf("*         * Book Data Base *        *\n");
    printf("****************\n");
    printf("%s", "\nEnter your choice\n"
           "   1 - INSERT BOOK DETAILES\n"
           "   2 - SEARCH OF BOOK\n"
           "   3 - DELETE OF BOOK\n"
           "   4 - UPDATE BOOK DETAILES\n"
           "   5 - DISPLAY ALL BOOKS DETAILES\n"
           "   6 - SELL BOOKS\n"
           "   7 - TO SAVE CHANGE\n");
    unsigned int menuChoice;
    printf("%s", "? ");
    scanf("%u", &menuChoice);
    return menuChoice;
}

