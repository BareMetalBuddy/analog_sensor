#ifndef TASK_H
#define TASK_H

#include <stdint.h>


/**
 * @enum States_t
 * @brief Represents the possible states of a task.
 */
typedef enum {BLOCKED, UNBLOCKED} States_t;

/**
 * @struct Task_t
 * @brief Represents a task in the system.
 *
 * @var Task_t::ticks
 * The task period in timer ticks.
 * @var Task_t::elapsed_time
 * Time since task's last execution, in timer ticks.
 * @var Task_t::function
 * Pointer to the function that the task executes.
 * @var Task_t::state
 * The current state of the task (blocked or unblocked).
 */
typedef struct {
	uint32_t ticks;
	uint32_t elapsed_time;	/* Time since task's last tick */
	void (*function)(void); /* Function to call for task's tick */
	States_t state;
}Task_t;


/**
 * @brief Initializes a task structure.
 *
 * @param task Pointer to the task structure to initialize.
 * @param ticks The task period in timer ticks.
 * @param elapsed_time Initial elapsed time since last tick.
 * @param f Pointer to the function that the task should execute.
 * @param state Initial state of the task.
 */
void task_init(Task_t *task,uint32_t ticks,uint32_t elapsed_time, void (*f)(), States_t state);

/**
 * @brief Changes the period of a task.
 *
 * @param task Pointer to the task structure.
 * @param ticks The new task period in timer ticks.
 */
void task_change_period(Task_t *task,uint32_t ticks);

/**
 * @brief Changes the state of a task.
 *
 * @param task Pointer to the task structure.
 * @param state The new state of the task.
 */
void task_change_state(Task_t *task, States_t state);

/**
 * @brief Deletes a task.
 *
 * Note: This function is not implemented in the provided code snippet.
 */
void task_delete(void);

#endif
