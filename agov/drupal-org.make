core = 8.x
api = 2

defaults[projects][subdir] = "contrib"

; Contrib modules
projects[admin_toolbar][version] = 1.16
projects[layout_plugin][version] = 1.0-alpha22
projects[ctools][version] = 3.0-alpha26
projects[default_content][version] = '1.0-alpha3'
projects[twitter_block][version] = 2.1
projects[linkicon][version] = '1.3'
projects[pathauto][version] = '1.0-alpha3'
projects[workbench_moderation][version] = '1.1'
projects[metatag][version] = '1.x-dev'
projects[agls][version] = '1.x-dev'
projects[scheduled_updates][version] = '1.0-alpha5'
projects[simple_sitemap][version] = '2.5'
projects[video_embed_field][version] = '1.2'
projects[embed][version] = '1.0-rc3'
projects[media_entity][version] = '1.5'
projects[media_entity_image][version] = '1.2'
projects[entity][version] = '1.0-alpha3'
projects[entity_embed][version] = '1.0-alpha3'
projects[entity_browser][version] = '1.0-alpha7'
projects[inline_entity_form][version] = '1.0-alpha6'
projects[token][version] = '1.0-beta1'
projects[fences][version] = '2.0-alpha1'

projects[page_manager][version] = '1.0-alpha23'
projects[page_manager][patch][] = https://www.drupal.org/files/issues/page-manager-contextual-temp.patch

projects[panels][version] = 3.0-beta5

; Development versions, no tagged releases or require bleeding edge features.

projects[better_normalizers][type] = module
projects[better_normalizers][download][type] = git
projects[better_normalizers][download][url] = https://git.drupal.org/project/better_normalizers.git
projects[better_normalizers][download][branch] = 8.x-1.x
projects[better_normalizers][download][revision] = 1cd9b4b50e91f5e595eb86813611dc368227c4b6

projects[title][type] = module
projects[title][download][type] = git
projects[title][download][url] = http://git.drupal.org/project/title.git
projects[title][download][branch] = 8.x-2.x
projects[title][download][revision] = b163e2d50b3add3842ac67ea11cced5eb5d7ceaf

; Require dev release for the "password_policy_character_types" policy type.
projects[password_policy][type] = module
projects[password_policy][download][type] = git
projects[password_policy][download][url] = http://git.drupal.org/project/password_policy.git
projects[password_policy][download][branch] = 8.x-3.x
projects[password_policy][download][revision] = 40f8e14bb6759ac201bffec0c5ffd0b4361c3e5b
projects[password_policy][patch][] = https://www.drupal.org/files/issues/2692709-undefined-indexes.patch
projects[password_policy][patch][] = https://www.drupal.org/files/issues/2697777-php7-1.patch

; No tagged release.
projects[media_entity_browser][type] = module
projects[media_entity_browser][download][type] = git
projects[media_entity_browser][download][url] = https://git.drupal.org/project/media_entity_browser.git
projects[media_entity_browser][download][branch] = 8.x-1.x
projects[media_entity_browser][download][revision] = 4abc37fcc374db7e5bd261e6c905d516e8e2f8b9

; Development Modules
projects[config_devel][version] = '1.0-rc1'
projects[config_devel][subdir] = 'development'
