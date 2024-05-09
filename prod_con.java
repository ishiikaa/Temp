import java.util.LinkedList;

public class ProducerConsumer {
    // Shared buffer between producer and consumer
    private LinkedList<Integer> buffer = new LinkedList<>();
    private int capacity;

    public ProducerConsumer(int capacity) {
        this.capacity = capacity;
    }

    // Function for the producer thread
    public void produce() throws InterruptedException {
        int value = 0;
        while (true) {
            synchronized (this) {
                // Wait if buffer is full
                while (buffer.size() == capacity) {
                    wait();
                }
                // Produce item and add to buffer
                buffer.add(value++);
                System.out.println("Produced: " + value);
                // Notify consumer thread that buffer is not empty
                notify();
                // Sleep for a while to simulate production time
                Thread.sleep(1000);
            }
        }
    }

    // Function for the consumer thread
    public void consume() throws InterruptedException {
        while (true) {
            synchronized (this) {
                // Wait if buffer is empty
                while (buffer.isEmpty()) {
                    wait();
                }
                // Consume item from buffer
                int value = buffer.removeFirst();
                System.out.println("Consumed: " + value);
                // Notify producer thread that buffer is not full
                notify();
                // Sleep for a while to simulate consumption time
                Thread.sleep(1000);
            }
        }
    }

    public static void main(String[] args) {
        final ProducerConsumer pc = new ProducerConsumer(5);

        // Create producer thread
        Thread producerThread = new Thread(() -> {
            try {
                pc.produce();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        // Create consumer thread
        Thread consumerThread = new Thread(() -> {
            try {
                pc.consume();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        // Start both threads
        producerThread.start();
        consumerThread.start();
    }
}
