import shutil, subprocess
from pathlib import Path

root = Path(__file__).resolve().parent

subprocess.check_call(['python', 'setup.py', 'build_ext', '--inplace'], cwd="cython-base")
subprocess.check_call(['python', 'setup.py', 'build_ext', '--inplace'], cwd="cython-derived")
subprocess.check_call(['python', 'setup.py', 'build_ext', '--inplace'], cwd="pybind11-base")
subprocess.check_call(['python', 'setup.py', 'build_ext', '--inplace'], cwd="pybind11-derived")

for f in root.glob("*/_skbuild/*/cmake-install/*"):
    shutil.copy2(f, root / f.name)

print(">> build finished.")
