#include "task.h"

/**
 * @brief Initializes a task structure.
 *
 * Sets up the task with the specified period, initial elapsed time, task function,
 * and initial state.
 *
 * @param task Pointer to the task structure to initialize.
 * @param ticks The task period in timer ticks.
 * @param elapsed_time Initial elapsed time since last tick.
 * @param f Pointer to the function that the task should execute.
 * @param state Initial state of the task.
 */
void task_init(Task_t *task,uint32_t ticks,uint32_t elapsed_time, void (*f)(), States_t state)
{
	task->ticks		    	= ticks;
	task->elapsed_time		= elapsed_time;
	task->function		    = f;
	task->state				= state;
}


/**
 * @brief Changes the period of a task.
 *
 * Adjusts the task's period to the new specified value and resets its elapsed time.
 *
 * @param task Pointer to the task structure.
 * @param ticks The new task period in timer ticks.
 */
void task_change_period(Task_t *task, uint32_t ticks)
{
	task->ticks		     = ticks;
	task->elapsed_time   = 0;
}


/**
 * @brief Changes the state of a task.
 *
 * Updates the task's state to either blocked or unblocked.
 *
 * @param task Pointer to the task structure.
 * @param state The new state of the task.
 */
void task_change_state(Task_t *task, States_t state)
{
	task->state = state;
}


/**
 * @brief Deletes a task.
 *
 * Note: This function is a placeholder and is not implemented in the provided code snippet.
 */
void task_delete(void)
{

}
