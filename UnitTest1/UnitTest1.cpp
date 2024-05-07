#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12.6/lab12.6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(IsEmptyOnInitialization)
        {
            Elem* first = nullptr;
            Elem* last = nullptr;
            Assert::IsTrue(isEmpty(first));
        }

        TEST_METHOD(EnqueueAndDequeue)
        {
            Elem* first = nullptr;
            Elem* last = nullptr;
            enqueue(first, last, 10);
            Assert::IsFalse(isEmpty(first));
            Assert::AreEqual(10, dequeue(first, last));
            Assert::IsTrue(isEmpty(first));
        }

        TEST_METHOD(CountElements)
        {
            Elem* first = nullptr;
            Elem* last = nullptr;
            enqueue(first, last, 5);
            enqueue(first, last, 10);
            enqueue(first, last, 15);
            Assert::AreEqual(3, countElements(first));
        }

        TEST_METHOD(CopyQueue)
        {
            Elem* first = nullptr;
            Elem* last = nullptr;
            Elem* copyFirst = nullptr;
            Elem* copyLast = nullptr;

            enqueue(first, last, 1);
            enqueue(first, last, 2);
            enqueue(first, last, 3);

            copyQueue(copyFirst, copyLast, first);

            Assert::AreEqual(3, countElements(copyFirst));
            Assert::AreEqual(1, dequeue(copyFirst, copyLast));
            Assert::AreEqual(2, dequeue(copyFirst, copyLast));
            Assert::AreEqual(3, dequeue(copyFirst, copyLast));
        }

        TEST_METHOD(LoadQueueFromFileTest)
        {
            Elem* first = nullptr;
            Elem* last = nullptr;
            const string testFilename = "test_data.txt";

            ofstream out(testFilename);
            out << "10 20 30";
            out.close();

            loadQueueFromFile(first, last, testFilename);

            Assert::IsFalse(isEmpty(first));
            Assert::AreEqual(10, dequeue(first, last));
            Assert::AreEqual(20, dequeue(first, last));
            Assert::AreEqual(30, dequeue(first, last));
            Assert::IsTrue(isEmpty(first));

            remove(testFilename.c_str());
        }
	};
}