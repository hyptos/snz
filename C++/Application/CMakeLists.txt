project ( ServerApplication  )

include_directories ("../")

add_subdirectory(Model)
add_subdirectory(Model/Entities)
add_subdirectory(Model/Entities/Agents)
add_subdirectory(Model/Entities/Agents/Bodies)
add_subdirectory(Model/Entities/Agents/Brains)
add_subdirectory(Model/Entities/Objects)
add_subdirectory(Model/Entities/Players)
add_subdirectory(Model/Info)
add_subdirectory(Server)
add_subdirectory(ServerApplication)
