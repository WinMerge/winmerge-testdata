
    print 'Upgrading VS solution- and project-file in folder: ' + root_path
    upgrade_projects(root_path)
    fix_proj_manifests(root_path)

# MAIN #
if __name__ == "__main__":
    main(sys.argv[1:])

