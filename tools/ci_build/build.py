import os
import sys
import argparse
import subprocess
import shutil
import logging

class BaseError(Exception):
    """Base class for errors originating from build.py."""
    pass


class BuildError(BaseError):
    """Error from running build steps."""

    def __init__(self, *messages):
        super().__init__("\n".join(messages))


class UsageError(BaseError):
    """Usage related error."""

    def __init__(self, message):
        super().__init__(message)

logging.basicConfig(format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
                        level=logging.INFO)
log = logging.getLogger(__name__)

def parse_arguments():
    parser = argparse.ArgumentParser()
    
    parser.add_argument(
            "--build_dir",
            required=True
    )

    parser.add_argument(
            "--config",
            required=True,
            help="Type of CMAKE_BUILD_TYPE"
    )

    parser.add_argument(
            "--cmake_path",
            default="cmake"
    )
    
    parser.add_argument(
            "--skip_unit_tests",
            action="store_true",
            help="Turn ON to skip all of unit tests"
    )

    parser.add_argument(
            "--use_sse",
            action='store_true',
            help="Turn ON to use sse_xx"
    )

    parser.add_argument(
            "--use_avx",
            action='store_true',
            help="Turn ON to use avx_xxx"
    )
    return parser.parse_args()

def generate_build_tree(cmake_path, source_dir, build_dir, args):
    cmake_dir = os.path.join(source_dir, 'cmake')
    cmake_args = [
            cmake_path, "-S", cmake_dir, "-B", build_dir,
            "-Dmmpack_USE_SSE=" + ("ON" if args.use_sse else "OFF"),
            "-Dmmpack_USE_AVX=" + ("ON" if args.use_avx else "OFF"),
            "-Dmmpack_BUILD_UNITTESTS=" + ("ON" if not args.skip_unit_tests else "OFF")
    ]

    return cmake_args

def resolve_executable_path(command_or_path):
    """Returns the absolute path of an executable."""
    executable_path = shutil.which(command_or_path)
    if executable_path is None:
        raise BuildError("Failed to resolve executable path for "
                         "'{}'.".format(command_or_path))
    return os.path.abspath(executable_path)

def try_create_dir(path):
    if not os.path.isdir(path):
        try:
            os.mkdir(path)
        except:
            os.makedirs(path)

def run_build(build_tree):
    return subprocess.run(build_tree)

def main():
    args = parse_arguments()

    script_dir = os.path.realpath(os.path.dirname(__file__))
    source_dir = os.path.normpath(os.path.join(script_dir, "..", ".."))

    if args.config in ['Debug', 'Release', 'RelWithDebInfo']:
        build_dir = args.build_dir + "/" + args.config
    else:
        raise UsageError("Unsupported type of config")
    
    cmake_path = resolve_executable_path(args.cmake_path)
    cmake_args = generate_build_tree(cmake_path, source_dir, build_dir, args)
    try_create_dir(build_dir)
    return run_build(cmake_args).returncode

if __name__ == '__main__':
    try:
        sys.exit(main())
    except BaseError as e:
        log.error(str(e))
        sys.exit(1)







