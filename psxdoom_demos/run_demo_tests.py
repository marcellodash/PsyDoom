############################################################################################################################################
# A small script that runs predefined sets of demos against PsyDoom in headless mode, verifying each demo result.
# Used for automated testing of the game.
#
# Usage:
#   python run_demo_tests.py <demoset> <psydoom_path> <demos_dir>
############################################################################################################################################
import multiprocessing
import os
import subprocess
import sys
import time

# These are the lists of demo sets and expected result files
demosets = {
    # PSX DOOM: "Greatest Hits" edition (v1.1)
    "doom" : [
        [ "DOOM_MAP{0:02}.LMP".format(i), "DOOM_MAP{0:02}.result.json".format(i) ] for i in range(1, 60)
    ]
}

# This function executes the demo in a worker process
def run_demo(demo_and_result, psydoom_path, demos_dir):
    # Show what demo we are about to run
    demo_path = os.path.join(demos_dir, demo_and_result[0])
    result_path = os.path.join(demos_dir, demo_and_result[1])    

    # Execute the demo using PsyDoom in headless mode and verify the result.
    # PsyDoom will return '0' if the demo was successful.
    result = subprocess.call(
        [psydoom_path, "-headless", "-playdemo", demo_path, "-checkresult", result_path],
        shell=False,
        stdout=subprocess.PIPE,     # Hide output
        stderr=subprocess.PIPE      # Hide output
    )

    # If the test failed (error code != 0) then inform the user.
    # Otherwise print that the test succeeded
    if result == 0:
        print("Test passed: {0:s}".format(demo_path))
    else:
        print("[TEST FAIL] Unexpected demo result!: {0:s}".format(demo_path))
        sys.exit(1)

# High level script logic
def main():    
    # Verify program args
    if len(sys.argv) != 4:
        print("Usage: python run_demo_tests.py <demoset> <psydoom_path> <demos_dir>")
        sys.exit(1)

    psydoom_path = sys.argv[2]
    demos_dir = sys.argv[3]

    # Verify demoset is okay
    demoset = demosets.get(sys.argv[1])

    if not demoset:
        print("Invalid demoset '{0:s}'!".format(sys.argv[1]))
        sys.exit(1)

    # Start running the demos and verify they match the expected results
    all_tests_passed = True
    start_time = time.time()
    jobs = []

    for demo_and_result in demoset:
        job = multiprocessing.Process(target=run_demo, args=(demo_and_result, psydoom_path, demos_dir,))
        job.start()
        jobs.append(job)

    for job in jobs:
        job.join()
        if job.exitcode != 0:
            all_tests_passed = False

    # Print the overall result
    if all_tests_passed:
        print("All tests executed successfully!")
    else:
        print("Some tests FAILED! Overall result is FAIL!")

    # Print time taken
    time_taken = time.time() - start_time
    print("Time taken: {0:f} seconds".format(time_taken))

# This is required for correct parallelism on Windows.
# See: https://stackoverflow.com/questions/18204782/runtimeerror-on-windows-trying-python-multiprocessing
if __name__ == '__main__':
    main()
