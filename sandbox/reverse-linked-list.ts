// Reverse a linked list with the typescript type system!

type ListNode = { data: number, next?: ListNode | undefined };
const LINKED_LIST = {
    data: 1,
    next:
    {
        data: 2,
        next:
        {
            data: 3,
            next:
            {
                data: 4
            }
        }
    }
} as const;

type Reverse<
    Current extends ListNode | undefined,
    Previous extends ListNode | undefined = undefined
> = Current extends ListNode
    ? Reverse<Current['next'], { data: Current['data'], next: Previous }>
    : Previous;

type ReversedList = Reverse<typeof LINKED_LIST>
