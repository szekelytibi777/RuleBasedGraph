docker build --pull --rm -f "Dockerfile" -t cppdev:latest "."
docker run --rm -it  --mount type=bind,source=c:\WORK\GIT\RuleBasedGraph,target=/dev_src cppdev:latest 