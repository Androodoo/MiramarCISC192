PART DDDDDDD

1. Differences between
    Pointer to stack memory
    Pointer to heap memory
    smart ptr (unique ptr)
            A ptr to stack mem only exists for a limited time, no need to remove because it goes away automatically, and then ptrs point to nothing
            A ptr to heap mem is like the ptr to stack but the memory does not go away automatically, you manually put in and take of memory. This also makes risk of data leaks
            A smart ptr is like a ptr to heap mem but the memory goes automatically away, this makes it safer from data leaks
2. Where and why delete was used
    I used delete in PART BBBB because it is a pointer to heap memory example. I had three tasks, and I completed two out of the three. After I was finished, I didn't want a data leaks so I decided to remove all the remaining tasks
3. Explanation of ownership in each design
    In a pointer to stack mem, the ownership belongs to no one, so nothing is responsible for removing data
        Example: the freeway with signs that point to which direction drivers are heading
    In a pointer to heap mem, the ownership belongs to the user, so they are responsible for managing the data
        Example: Rental storage where when I am done with the storage, I am responsible to take my stuff out or else its gone
    In a smart pointer, the ownership belongs to the stack, and it automatically manages the data when done
        Example: Someone eats at my house and cleans after themself, leaving nothing behind
4. Which ptr method is safest and why
    The smart pointer method is the safest because it is automatic with deleting memory and prevents data leaks, and it has super clear ownerships with so no double deletes

UML DIAGRAMS

    PartC
    - tasks: std::unique_ptr<Task[]>
    - size: int
    - capacity: int
    --------------------------------
    + PartC(initialCapacity: int)
    + addTask(desc: const std::string&): void
    + removeTask(id: int): void
    + listTasks(): void

    Task
    - id: int
    - description: string
    - completed: bool
    --------------------------------
    + Task()
    + Task(id: int, descL const std::string)
    + markCompleted(): void
    + isCompleted(): bool
    + getId(): int
    + getDescription(): string

Notes
Okay this project was actually really fun
I could not run the code due to the CMake files from the previous lab, so to run it, I entered g++ main.cpp task.cpp -o main, and .\main
I tried making multiple header files for the parts but I couldnt do it </3
    I think that I should have just done PartA.cpp, PartA.h, and so on, so that I could have multiple mains. but now it is a little too late to do it lol.
This project taught me a lot about pointers, I never even knew that they existed
